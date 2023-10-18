#include "monty.h"

/**
 * _div - divides the second element by the top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _div(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *lax = NULL;

	lax = *doubly;

	for (; lax != NULL; lax = lax->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", cline);
		free_glov();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_glov();
		exit(EXIT_FAILURE);
	}

	lax = (*doubly)->next;
	lax->n /= (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _mul - multiplies the top element to the second top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _mul(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *lax = NULL;

	lax = *doubly;

	for (; lax != NULL; lax = lax->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", cline);
		free_glov();
		exit(EXIT_FAILURE);
	}

	lax = (*doubly)->next;
	lax->n *= (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _mod - computes the rest of the division of the second element
 * by the top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _mod(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *lax = NULL;

	lax = *doubly;

	for (; lax != NULL; lax = lax->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", cline);
		free_glov();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_glov();
		exit(EXIT_FAILURE);
	}

	lax = (*doubly)->next;
	lax->n %= (*doubly)->n;
	_pop(doubly, cline);
}
/**
 * _pchar - print the char value of the first element
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _pchar(stack_t **doubly, unsigned int cline)
{
	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", cline);
		free_glov();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n < 0 || (*doubly)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", cline);
		free_glov();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*doubly)->n);
}

/**
 * _pstr - prints the string of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _pstr(stack_t **doubly, unsigned int cline)
{
	stack_t *lax;
	(void)cline;

	lax = *doubly;

	while (lax && lax->n > 0 && lax->n < 128)
	{
		printf("%c", lax->n);
		lax = lax->next;
	}

	printf("\n");
}
