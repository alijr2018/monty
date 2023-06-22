#include "monty.h"

/**
 * _add - This function adds the two topmost elements of the stack.
 * @stack: A pointer pointing to the top of the stack.
 * @L_nbr:  The line number where it is referenced.
 * Return: 1 if successful, otherwise returns nothing but 2.
 */
void _add(stack_t **stack, unsigned int L_nbr)
{
	stack_t *i, *j;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", L_nbr);
		fclose(file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		i = *stack;
		j = i->next;
		j->n += i->n;
		*stack = j;
		(*stack)->prev = NULL;
		free(i);
	}
}

/**
 *  _free - Free stack
 *  @stack: Pointer to the stack
 *  Return: Void
 */

void _free(stack_t *stack)
{
	if (stack)
	{
		_free(stack->next);
		free(stack);
	}
}

/**
 *  _where - Indicates the absence of an operation.
 *  @stack: Header of stack
 *  @L_nbr: Integer representing line numbers.
 *  Return: Void
 */


void _where(stack_t **stack, unsigned int L_nbr)
{

	(void) stack;
	(void) L_nbr;
}

/**
 * _pall - A function that displays all elements stored in the stack.
 * @stack: is a pointer pointing to the head of the stack.
 * @L_nbr: represents the line number where the instruction is located.
 * associated with the "push" and "pall" instructions.
 * Return: if fail return EXIT_FAILURE else return value.
 */
void _pall(stack_t **stack, unsigned int L_nbr)
{
	stack_t *present;

	(void)L_nbr;
	present = *stack;

	while (present != NULL)
	{
		printf("%d", present->n);
		present = present->next;
		printf("\n");
	}
}

/**
 * _pint - A function that prints the top element on the stack.
 * @stack: Pointer to the head of the stack.
 * @L_nbr: indicates the location of the instruction.
 * the pint opcode
 * Return: if fail return EXIT_FAILURE else return value.
 */
void _pint(stack_t **stack, unsigned int L_nbr)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", L_nbr);
		fclose(file);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
