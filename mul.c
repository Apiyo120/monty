#include "monty.h"

/**
 * mul - Multiplies the second top element of the stack with the top element.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number being executed from the bytecode file.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
