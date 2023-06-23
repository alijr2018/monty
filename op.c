#include "monty.h"

/**
 * search - Operators
 *
 * @op_f: Char pointer
 * @l: line
 * @stak: stack
 *
 * Return: Void
 */
void (*search(char *op_f, unsigned int l, stack_t **stak))
(stack_t**, unsigned int)
{
	int count;

	instruction_t operation[] = {
		{"pall", _pall},
		{"add", _add},
		{"pint", _pint},
		{"swap", _swap},
		{"pop", _pop},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL}
	};

	for (count = 0; operation[count].opcode != NULL; count++)
	{
		if (strcmp(operation[count].opcode, op_f) == 0)
		{
			return (operation[count].f);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", l, op_f);
	fclose(file);
	_freestack(*stak);
	exit(EXIT_FAILURE);
}

