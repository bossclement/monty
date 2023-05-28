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
 * mod - computes the rest of the division of the second top element
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
	} else if ((*stack)->n == 0)
	{
		sprintf(msg, "L%u: division by zero", line_number + 1);
		error(msg, *stack, EXIT_FAILURE);
	}

	next = head->next;
	next->n = next->n % head->n;
	next->prev = NULL;
	*stack = next;
	free(head);
}

/**
 * pchar - prints the char at the top of the stack.
 * @stack: pointer to a node.
 * @line_number: int var - line number of node.
 */
void pchar(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	char msg[1024];

	if (*stack == NULL)
	{
		sprintf(msg, "L%u: can't pchar, stack empty", line_number + 1);
		error(msg, *stack, EXIT_FAILURE);
	}
	else if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		sprintf(msg, "L%u: can't pchar, value out of range", line_number + 1);
		error(msg, *stack, EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack.
 * @stack: pointer to a node.
 * @line_number: int var - line number of node.
 */
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *node = *stack;

	while (node)
	{
		if (node->n <= 0 || node->n > 127)
			break;
		printf("%c", node->n);
		node = node->next;
	}

	printf("\n");
}
