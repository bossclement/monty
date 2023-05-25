#include "main.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to a node
 * @line_number: int var - line number of node
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	stack_t *next = NULL;
	stack_t *temp;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		print("%d\n", temp->n);
		temp = temp->next;
	}
}

