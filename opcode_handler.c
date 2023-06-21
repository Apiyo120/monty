#include "monty.h"

/**
 * get_instruction - Retrieves instruction associated with the given opcode.
 *
 * @opcode: The opcode for which to retrieve the instruction.
 *
 * Return: instruction_t struct representing instruction associated with opcode
 *         If the opcode is not recognized, the returned instruction_t struct
 *         will have a NULL function pointer.
 */

instruction_t get_instruction(char *opcode)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},

		{NULL, NULL}};

	int z = 0;

	while (instructions[z].opcode != NULL)
	{
		if (strcmp(opcode, instructions[z].opcode) == 0)
			return (instructions[z]);
		z++;
	}
	return (instructions[z]);
}
