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
	size_t bufsize = 1024, j;
	ssize_t get_line;
	char  *s = NULL, *op_a[2], *t;

	j = 0;

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
		op_a[0] = strtok(s, "\n ");
		if (op_a[0] == NULL)
			_where(&n, j);
		else if (strcmp("push", op_a[0]) == 0)
		{
			t = strtok(NULL, "\n ");
			_push(&n, j, t);
		}
		else if (op_a[0] != NULL && op_a[0][0] != '#')
		{
			f_op = se(op_a[0], j, &n);

			if (f_op == NULL && j == 0)
			{
				fprintf(stderr, "L%ld: unknown instruction %s\n", j, op_a[0]);
					 exit(EXIT_FAILURE);
			}
		f_op(&n, j);
		}
	}
	fclose(file), free(s), _free(n);
	return (0);
}
