#include "monty.h"

/**
 * mul_nodes - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
        more_err(8, line_number, "mul");
        return;
    }

    *stack = (*stack)->next;
    (*stack)->n *= (*stack)->prev->n;

    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * mod_nodes - Computes the modulus of the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
        more_err(8, line_number, "mod");
        return;
    }

    if ((*stack)->n == 0)
    {
        more_err(9, line_number);
        return;
    }

    *stack = (*stack)->next;
    (*stack)->n %= (*stack)->prev->n;

    free((*stack)->prev);
    (*stack)->prev = NULL;
}
