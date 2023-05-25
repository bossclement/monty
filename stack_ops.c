#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to a node
 * @line_number: int var - line number of node
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	char msg[1024];

	if (stack == NULL)
	{
		sprintf(msg, "L%u: can't pint, stack empty", line_number);
		error(msg, *stack, EXIT_FAILURE);
	}
	while (head->next)
		head = head->next;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->prev;
	}
}

