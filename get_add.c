#include "monty.h"

/**
 * get_add - function that adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: where the line number appears
 * Description: 4. add
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */
void get_add(stack_t **stack, unsigned int line_number)
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
 *  get_free - Free stack
 *
 *  @stack: Stack pointer
 *
 *  Return: Void
 */


void get_free(stack_t *stack)
{
	if (stack)
	{
		get_free(stack->next);
		free(stack);
	}
}

/**
 *  get_nop - When no operation present
 *
 *  @stack: Header of stack
 *
 *  @line_number: Integer of line numbers
 *
 *  Return: Void
 */


void get_nop(stack_t **stack, unsigned int line_number)
{

	(void) stack;
	(void) line_number;
}

/**
 * get_pall - function that prints all elements on the stack
 * @stack: pointer to head of the stack
 * @line_number: where the instruction appears
 * Description: 0. push, pall
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */
void get_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;

	while (current != NULL)
	{
		printf("%d", current->n);
		current = current->next;
		printf("\n");
	}
}

/**
 * get_pint - function that prints the top element on the stack
 * @stack: pointer to head of the stack
 * @line_number: where the instruction appears
 * Description: 1. pint
 * Return: see below
 * 1. upon success, nothing
 * 2. upon fail, EXIT_FAILURE
 */
void get_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
