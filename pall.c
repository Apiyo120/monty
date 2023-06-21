#include "monty.h"

/**
 * pall - Prints all the elements in the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The line number in the source file
 * where the pall instruction appears.
 *
 */


void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
