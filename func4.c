#include "monty.h"

/**
 * _sub - substract the top element fromthe second top element 
 * of the stack.
 * @stack: pointer to stack
 * @line_number: line number
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	int res;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		fclose(file);
		_freestack(*stack);
		exit(EXIT_FAILURE);
	}

	res = (*stack)->next->n - (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
	(*stack)->n = res;
}
