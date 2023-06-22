#include "monty.h"

/**
 * add - Adds a new element to the top of the stack.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The line number where the function is called.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if	(*stack == NULL || (*stack)->next == NULL)

	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
