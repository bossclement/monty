#include "monty.h"

/**
 * mul -  multiplies the second top element of the
 *	stack with the top element of the stack.
 * @stack: pointer to a node.
 * @line_number: int var - line number of node.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *next;
	char msg[1024];

	if (*stack == NULL || (*stack)->next == NULL)
	{
		sprintf(msg, "L%u: can't add, stack too short", line_number + 1);
		error(msg, *stack, EXIT_FAILURE);
	}

	next = head->next;
	next->n *= head->n;
	next->prev = NULL;
	*stack = next;
	free(head);
}

/**
 * mod -   computes the rest of the division of the second top element
 *	of the stack by the top element of the stack.
 * @stack: pointer to a node.
 * @line_number: int var - line number of node.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *next;
	char msg[1024];

	if (*stack == NULL || (*stack)->next == NULL)
	{
		sprintf(msg, "L%u: can't mod, stack too short", line_number + 1);
		error(msg, *stack, EXIT_FAILURE);
	}

	next = head->next;
	next->n = next->n % head->n;
	next->prev = NULL;
	*stack = next;
	free(head);
}
