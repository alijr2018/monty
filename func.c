#include "monty.h"

/**
 * _add - This function adds the two topmost elements of the stack.
 * @stack: A pointer pointing to the top of the stack.
 * @line_number:  The line number where it is referenced.
 * Return: 1 if successful, otherwise returns nothing but 2.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		first = *stack;
		second = first->next;
		second->n += first->n;
		*stack = second;
		(*stack)->prev = NULL;
		free(first);
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
 *  @line_number: Integer representing line numbers.
 *  Return: Void
 */


void _where(stack_t **stack, unsigned int line_number)
{

	(void) stack;
	(void) line_number;
}

/**
 * _pall - A function that displays all elements stored in the stack.
 * @stack: is a pointer pointing to the head of the stack.
 * @line_number: represents the line number where the instruction is located.
 * associated with the "push" and "pall" instructions.
 * Return: if fail return EXIT_FAILURE else return value.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *present;

	(void)line_number;
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
 * @line_number: indicates the location of the instruction.
 * the pint opcode
 * Return: if fail return EXIT_FAILURE else return value.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(file);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
