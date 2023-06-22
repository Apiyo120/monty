#include "monty.h"

/**
 * execute_instruction - Retrieves instruction associated with given opcode.
 *
 * @opcode: The opcode for which to retrieve the instruction.
 * @stack: stack
 * @line_number: unsigned int
 *
 * Return: instruction_t struct representing instruction associated with opcode
 *         If the opcode is not recognized, the returned instruction_t struct
 *         will have a NULL function pointer.
 */

void execute_instruction(char *opcode, stack_t **stack,
				unsigned int line_number)
{
	size_t z;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},

		{NULL, NULL}
	};

	for (z = 0; instructions[z].opcode != NULL; z++)
	{
		if (strcmp(opcode, instructions[z].opcode) == 0)
		{
			instructions[z].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
