#include "monty.h"

global_t glov;

/**
 * free_glov - frees the global variables
 *
 * Return: no return
 */
void free_glov(void)
{
	free_dlistint(glov.head);
	free(glov.buffer);
	fclose(glov.fd);
}

/**
 * start_glov - initializes the global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void start_glov(FILE *fd)
{
	glov.lifo = 1;
	glov.cont = 1;
	glov.arg = NULL;
	glov.head = NULL;
	glov.fd = fd;
	glov.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_glov(fd);
	nlines = getline(&glov.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = _strtoky(glov.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", glov.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_glov();
				exit(EXIT_FAILURE);
			}
			glov.arg = _strtoky(NULL, " \t\n");
			f(&glov.head, glov.cont);
		}
		nlines = getline(&glov.buffer, &size, fd);
		glov.cont++;
	}

	free_glov();

	return (0);
}
