#include "monty.h"

/**
 * _rotl - rotates the first element to the bottom and  the second to the top
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _rotl(stack_t **doubly, unsigned int cline)
{
	stack_t *lax1 = NULL;
	stack_t *lax2 = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	lax1 = (*doubly)->next;
	lax2 = *doubly;

	for (; lax2->next != NULL; lax2 = lax2->next)
		;

	lax1->prev = NULL;
	lax2->next = *doubly;
	(*doubly)->next = NULL;
	(*doubly)->prev = lax2;
	*doubly = lax1;
}

/**
 * _rotr - reverse the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _rotr(stack_t **doubly, unsigned int cline)
{
	stack_t *lax = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	lax = *doubly;

	for (; lax->next != NULL; lax = lax->next)
		;

	lax->prev->next = NULL;
	lax->next = *doubly;
	lax->prev = NULL;
	(*doubly)->prev = lax;
	*doubly = lax;
}
