#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to a node
 * @line_number: int var - line number of node
 */
void pint(stack_t **stack, unsigned int line_number)
{
	char msg[1024];

	if (*stack == NULL)
	{
		sprintf(msg, "L%u: can't pint, stack empty", line_number + 1);
		error(msg, *stack, EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * nop - does nothing
 * @stack: pointer to a node
 * @line_number: int var - line number of node
 */
void nop(stack_t **stack __attribute__((unused)),
unsigned int line_number __attribute__((unused)))
{
}

/**
 * swap - waps the top two elements of the stack.
 * @stack: pointer to a node
 * @line_number: int var - line number of node
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack, *second;
	char msg[1024];

	if (*stack == NULL || (*stack)->next == NULL)
	{
		sprintf(msg, "L%u: can't swap, stack too short", line_number + 1);
		error(msg, *stack, EXIT_FAILURE);
	}

	second = first->next;

	first->next = second->next;
	first->prev = second->next;
	second->next = first;
	second->prev = NULL;
	*stack = second;
}

/**
 * sub - subtracts the top element of the stack from the
 *	second top element of the stack.
 * @stack: pointer to a node.
 * @line_number: int var - line number of node.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *next;
	char msg[1024];
	int res = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		sprintf(msg, "L%u: can't sub, stack too short", line_number + 1);
		error(msg, *stack, EXIT_FAILURE);
	}

	res = head->next->n - head->n;
	head->n = res;
	next = head->next;
	head->next = head->next->next;
	free(next);
}

/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to a node.
 * @line_number: int var - line number of node.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *next;
	char msg[1024];

	if (*stack == NULL || (*stack)->next == NULL)
	{
		sprintf(msg, "L%u: can't add, stack too short", line_number + 1);
		error(msg, *stack, EXIT_FAILURE);
	}

	head->n += head->next->n;
	next = head->next;
	head->next = head->next->next;
	free(next);
}
