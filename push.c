#include "monty.h"

/**
 * push - Pushes an integer onto the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The line number in the source file
 * where the push instruction appears.
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *num_str = strtok(NULL, " \n");
	int num;
	stack_t *new_node;

	if (num_str == NULL || sscanf(num_str, "%d", &num) != 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
