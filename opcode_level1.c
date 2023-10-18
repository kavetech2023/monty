#include "monty.h"

/**
 * _push - pushes an element to the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _push(stack_t **doubly, unsigned int cline)
{
	int n, j;

	if (!glov.arg)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_glov();
		exit(EXIT_FAILURE);
	}

	for (j = 0; glov.arg[j] != '\0'; j++)
	{
		if (!isdigit(glov.arg[j]) && glov.arg[j] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_glov();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(glov.arg);

	if (glov.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
 * _pall - prints all values on the stack
 *
 * @doubly: head of the linked list
 * @cline: line numbers
 * Return: no return
 */
void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *lax;
	(void)cline;

	lax = *doubly;

	while (lax)
	{
		printf("%d\n", lax->n);
		lax = lax->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "can't pint, stack empty\n");
		free_glov();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}

/**
 * _pop - removes the top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _pop(stack_t **doubly, unsigned int cline)
{
	stack_t *lax;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline);
		free_glov();
		exit(EXIT_FAILURE);
	}
	lax = *doubly;
	*doubly = (*doubly)->next;
	free(lax);
}

/**
 * _swap - swaps the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _swap(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *lax = NULL;

	lax = *doubly;

	for (; lax != NULL; lax = lax->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline);
		free_glov();
		exit(EXIT_FAILURE);
	}

	lax = *doubly;
	*doubly = (*doubly)->next;
	lax->next = (*doubly)->next;
	lax->prev = *doubly;
	(*doubly)->next = lax;
	(*doubly)->prev = NULL;
}
