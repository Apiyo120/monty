#include "monty.h"

#define MAX_LINE_LENGTH 1024

/**
 * main - The entry point for the Monty Interp program.
 *
 * @argc: The count of arguments passed to the program.
 * @argv: Pointer to an array of char pointers to arguments.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */

int main(int argc, char *argv[])
{

	char line[1024];
	FILE *script;
	unsigned int line_number = 0;
	char *opcode;
	stack_t *stack = NULL;
	stack_t *temp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	script = fopen(argv[1], "r");

	if (script == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), script) != NULL)
	{
		line_number++;
		if (strlen(line) > 1)
		{
			opcode = strtok(line, " \n");

			if (opcode != NULL && opcode[0] != '#')
				execute_instruction(opcode, &stack, line_number);
		}
	}
	fclose(script);
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	return (EXIT_SUCCESS);
}
