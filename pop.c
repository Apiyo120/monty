#include "monty.h"

/**
 * pop - Removes the top element from the stack.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The line number where the function is called
 */

void pop(stack_t **stack, unsigned int line_number)
{

	stack_t *temp;

	if	(*stack == NULL)

	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if	(*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
