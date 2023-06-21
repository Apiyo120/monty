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
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *opcode, *filename, *line = NULL;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	filename = argv[1];
	file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}
	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \n");
		if (opcode != NULL && opcode[0] != '#')
		{
			instruction_t instruction = get_instruction(opcode);

			if (instruction.f == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				free(line);
				fclose(file);
				return (EXIT_FAILURE);
			}
			instruction.f(&stack, line_number);
		}
	}
	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}
