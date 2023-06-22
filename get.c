#include "monty.h"

/**
 * _pop - A function that Pops the top element from the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number:  Line number where it appears.
 * pop operation.
 * Return: if failed return EXIT_FAILURE esle return void.
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *i;

	if ((*stack == NULL) || (stack == NULL))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(file);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
	i = *stack;
	*stack = (*stack)->next;
	if (i->next)
	{
		i->next->prev = NULL;
	}
	free(i);
}


/**
 * _push - A fuction responsible for adding an element to the top of the stack.
 * @stack: Is a pointer that references the top of the stack.
 * @line_number: Indicates the line number where the function is called.
 * @temp: Is a pointer to the instruction.
 * connect with push, pall
 * Return: if fails returns EXIT_FAILURE else return void.
 */

void _push(stack_t **stack, unsigned int line_number, char *temp)
{

	stack_t *new_top;

	(void)line_number;

	if (temp == NULL || _isdigit(temp) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(file);
		_free(*stack);
		exit(EXIT_FAILURE);
		if (_isdigit(temp) == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(file);
			_free(*stack);
			exit(EXIT_FAILURE);
		}
	}
	new_top = malloc(sizeof(stack_t));
	if (new_top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	new_top->n = atoi(temp);
	new_top->next = NULL;
	new_top->prev = NULL;
	if (*stack)
	{
		new_top->next = *stack;
		(*stack)->prev = new_top;
		*stack = new_top;
	}
	*stack = new_top;
}


/**
 *  _isdigit - Determines whether a character is a digit or not.
 *  @str: represents the character being tested.
 *  Return: 1 for digit, 0 if not
 */

int _isdigit(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
		{
			return (1);
		}
		i++;
	}

	return (0);
}

/**
 * _swap - is a function that exchanges the positions,
 * of the top two elements in the stack.
 * @stack: is a pointer indicating the top of the stack.
 * @line_number: indicates the line number where the function is invoked.
 * Return: In case failure returns EXIT_FAILURE else return void.
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *i, *j;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(file);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
	else if (*stack)
	{
		i = *stack;
		j = i->next;
		*stack = j;
		i->next = j->next;
		if (j->next != NULL)
		{
			j->next->prev = i;
		}
		j->prev = NULL;
		j->next = i;
		i->prev = j;
	}
}
