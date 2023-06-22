#include "monty.h"

/**
 * se - Operators
 * @op_f: Pointer to a character.
 * @l: Line.
 * @stak: stack.
 * Return: Void.
 */

void (*se(char *op_f, unsigned int l, stack_t **stak))(stack_t**, unsigned int)
{
	int i;

	instruction_t operation[] = {
		{"pall", _pall},
		{"add", _add},
		{"pint", _pint},
		{"swap", _swap},
		{"pop", _pop},
		{"nop", _where},
		{NULL, NULL}
	};

	for (i = 0; operation[i].opcode != NULL; i++)
	{
		if (strcmp(operation[i].opcode, op_f) == 0)
		{
			return (operation[i].f);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", l, op_f);
	fclose(file);
	_free(*stak);
	exit(EXIT_FAILURE);
}
