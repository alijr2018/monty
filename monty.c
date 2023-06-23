#include "monty.h"

FILE *file;

/**
 *  main - The monty program
 *  @argc: Number of args
 *  @argv: Command line args
 *  Return: Void
 */
int main(int argc, char *argv[])
{
	stack_t *head = NULL;
	char *str = NULL, *operator_array[2], *temp;
	size_t line_count = 0, bufsize = BUFSIZE;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (_getline(&str, &bufsize, file) != EOF)
	{
		line_count++;
		operator_array[0] = strtok(str, "\n ");
		if (operator_array[0] == NULL)
		{
			_nop(&head, line_count);
		}
		else if (strcmp("push", operator_array[0]) == 0)
		{
			temp = strtok(NULL, "\n ");
			_push(&head, line_count, temp);
		}
		else if (operator_array[0] != NULL && operator_array[0][0] != '#')
		{
			void (*operator_function)(stack_t **, unsigned int);

			operator_function = search(operator_array[0], line_count, &head);
			if (operator_function == NULL)
			{
				fprintf(stderr, "L%lu: unknown instruction %s\n", line_count, operator_array[0]);
				fclose(file);
				_freestack(head);
				exit(EXIT_FAILURE);
			}
			operator_function(&head, line_count);
		}
	}
	fclose(file), _freestack(head);
	return (0);
}

