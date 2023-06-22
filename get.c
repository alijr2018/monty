#include "monty.h"

/**
 * _pop - A function that Pops the top element from the stack.
 * @stack: Pointer to the top of the stack.
 * @L_nbr:  Line number where it appears.
 * pop operation.
 * Return: if failed return EXIT_FAILURE esle return void.
 */

void _pop(stack_t **stack, unsigned int L_nbr)
{
	stack_t *i;

	if ((*stack == NULL) || (stack == NULL))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", L_nbr);
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
 * @L_nbr: Indicates the line number where the function is called.
 * @t: Is a pointer to the instruction.
 * connect with push, pall
 * Return: if fails returns EXIT_FAILURE else return void.
 */

void _push(stack_t **stack, unsigned int L_nbr, char *t)
{

	stack_t *_n;

	(void)L_nbr;

	if (t == NULL || _isdigit(t) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", L_nbr);
		fclose(file);
		_free(*stack);
		exit(EXIT_FAILURE);
		if (_isdigit(t) == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", L_nbr);
			fclose(file);
			_free(*stack);
			exit(EXIT_FAILURE);
		}
	}
	_n = malloc(sizeof(stack_t));
	if (_n == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	_n->n = atoi(t);
	_n->next = NULL;
	_n->prev = NULL;
	if (*stack)
	{
		_n->next = *stack;
		(*stack)->prev = _n;
		*stack = _n;
	}
	*stack = _n;
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
 * @L_nbr: indicates the line number where the function is invoked.
 * Return: In case failure returns EXIT_FAILURE else return void.
 */

void _swap(stack_t **stack, unsigned int L_nbr)
{
	stack_t *i, *j;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", L_nbr);
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
