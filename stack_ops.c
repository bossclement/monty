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
		sprintf(msg, "L%u: can't pint, stack empty", line_number);
		error(msg, *stack, EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * nop - does nothing
 * @stack: pointer to a node
 * @line_number: int var - line number of node
 */
void nop(stack_t **stack __attribute__((unused)), unsigned int line_number)
{
	(void)line_number;
}
