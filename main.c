#include "monty.h"

/**
 *  main - The monty program
 *  @argc: Number of args
 *  @argv: Command line args
 *  Return: Void
 */

int main(int argc, char *argv[])
{
	stack_t *n = NULL;
	char  *s = NULL, *operator_array[2], *t;
	size_t bufsize = 1024, j = 0;
	ssize_t get_line;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	while (1)
	{
		get_line = getline(&s, &bufsize, file);
		if (get_line == -1)
			break;
		j++;
		operator_array[0] = strtok(s, "\n ");
		if (operator_array[0] == NULL)
			_where(&n, j);
		else if (strcmp("push", operator_array[0]) == 0)
		{
			t = strtok(NULL, "\n ");
			_push(&n, j, t);
		}
		else if (operator_array[0] != NULL && operator_array[0][0] != '#')
		{
			operator_function = se(operator_array[0], j, &n);

			if (operator_function == NULL && j == 0)
			{
				fprintf(stderr, "L%ld: unknown instruction %s\n",
					j, operator_array[0]), exit(EXIT_FAILURE);
			}
		operator_function(&n, j);
		}
	}
	fclose(file), free(s), _free(n);
	return (0);
}
