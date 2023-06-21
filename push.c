#include "monty.h"

/**
 * push - Pushes an integer onto the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The line number in the source file
 * where the push instruction appears
 */

void push(stack_t **stack, unsigned int line_number)
{
	int value = 0;
	stack_t *new_node;

	(void)line_number;

	new_node = malloc(sizeof(stack_t));


	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
