#include "monty.h"

/**
 * find_opcodes - function that maps the opecodes to their functions
 *
 * @opcd: opcode passed
 *
 * Return: a pointer that points to the function to execute
 */
void (*find_opcodes(char *opcd))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction[] = {
		{"push", _pushstck},
		{"pall", _pallstck},
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", op_swap},
		{"add", add_two},
		{"nop", nop_op},
		{"sub", sub_op},
		{"div", div_op},
		{"mul", mul_op},
		{"mod", _modulus},
		{"pchar", _printch},
		{"pstr", _pstr},
		{"rotl", rot_top},
		{"rotr", rot_rev},
		{"stack", stack_op},
		{"queue", queue_op},
		{NULL, NULL}
	};
	int p;

	for (p = 0 ; instruction[p].opcode ; p++)
	{
		if (_strcmp_(instruction[p].opcode, opcd) == 0)
			break;
	}

	return (instruction[p].f);
}

