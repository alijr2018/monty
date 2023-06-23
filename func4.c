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

/**
 * _div - divide the top element fromthe second top element
 * of the stack.
 * @stack: pointer to stack
 * @line_number: line number
 */

void _div(stack_t **stack, unsigned int line_number)
{
        int res;
        stack_t *temp;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
                fclose(file);
                _freestack(*stack);
                exit(EXIT_FAILURE);
        }

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		fclose(file);
		_freestack(*stack);
		exit(EXIT_FAILURE);
	}

        res = (*stack)->next->n / (*stack)->n;
        temp = *stack;
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        free(temp);
        (*stack)->n = res;
}


/**
 * _mul - mutiplies the top element fromthe second top element
 * of the stack.
 * @stack: pointer to stack
 * @line_number: line number
 */

void _mul(stack_t **stack, unsigned int line_number)
{
        int res;
        stack_t *temp;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
                fclose(file);
                _freestack(*stack);
                exit(EXIT_FAILURE);
        }

        res = (*stack)->next->n * (*stack)->n;
        temp = *stack;
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        free(temp);
        (*stack)->n = res;
}

/**
 * _mod - compute the rest of the divionn the second top element
 * of the stack.
 * @stack: pointer to stack
 * @line_number: line number
 */

void _mod(stack_t **stack, unsigned int line_number)
{
        int res;
        stack_t *temp;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
                fclose(file);
                _freestack(*stack);
                exit(EXIT_FAILURE);
        }

        if ((*stack)->n == 0)
        {
                fprintf(stderr, "L%u: division by zero\n", line_number);
                fclose(file);
                _freestack(*stack);
                exit(EXIT_FAILURE);
        }

        res = (*stack)->next->n % (*stack)->n;
        temp = *stack;
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        free(temp);
        (*stack)->n = res;
}
