#include "monty.h"

/**
 * push - Pushes an integer onto the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number being executed from the script file
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int value;
	stack_t *new_node;

	arg = strtok(NULL, " \t\n");
	if (arg == NULL || !is_numeric(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);

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

/**
 * is_numeric - Checks if a string is numeric
 * @str: The string to check
 *
 * Return: 1 if the string is numeric, 0 otherwise
 */
int is_numeric(char *str)
{
	if (*str == '-')
		str++;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
