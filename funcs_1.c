#include "monty.h"

/**
 * two_args - prints by new line.
 * @oper: operations.
 * Return: number
 */

int two_args(char *oper)
{
	if (oper == NULL)
		return (0);

	if (strcmp(oper, "push") == 0)
		return (1);

	return (0);
}
