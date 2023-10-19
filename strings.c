#include "monty.h"

/**
 * print_char - Prints the ASCII character represented by the top element of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 *
 * This function checks if the stack is not empty and the top element's value is a valid
 * ASCII value (between 0 and 127). If so, it prints the corresponding character.
 * If the stack is empty or the value is out of range, it triggers an error.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL || *stack == NULL)
        string_err(11, line_number);

    int ascii_value = (*stack)->n;
    if (ascii_value < 0 || ascii_value > 127)
        string_err(10, line_number);

    printf("%c\n", ascii_value);
}

/**
 * print_str - Prints a string by interpreting the stack's elements as ASCII characters.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 *
 * This function prints a sequence of characters by interpreting the stack's elements
 * as ASCII values. It continues to print characters until an element is not a valid
 * ASCII value (outside the range of 0 to 127) or the stack is empty.
 */
void print_str(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL || *stack == NULL)
    {
        printf("\n");
        return;
    }

    stack_t *current = *stack;
    while (current != NULL)
    {
        int ascii_value = current->n;
        if (ascii_value <= 0 || ascii_value > 127)
            break;

        printf("%c", ascii_value);
        current = current->next;
    }

    printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 *
 * This function rotates the first node of the stack to the bottom, maintaining
 * the order of the other nodes. If the stack is empty or has only one element,
 * it does nothing.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;

    stack_t *tmp = *stack;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = *stack;
    (*stack)->prev = tmp;
    *stack = (*stack)->next;
    (*stack)->prev->next = NULL;
    (*stack)->prev = NULL;
}

/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 *
 * This function rotates the last node of the stack to the top, preserving
 * the order of the other nodes. If the stack is empty or has only one element,
 * it does nothing.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;

    stack_t *tmp = *stack;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = *stack;
    tmp->prev->next = NULL;
    tmp->prev = NULL;
    (*stack)->prev = tmp;
    (*stack) = tmp;
}
