/**
 * pint - Prints the value of the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The line number in the source file
 * where the pint instruction appears.
 */

#include "monty.h"

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
