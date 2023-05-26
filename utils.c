#include "monty.h"

/**
 * split_oper - removes unneccessary space in the oper.
 * @line: line of text read from monty file.
 * @oper: where to store the oper.
 * Return: length of the oper.
 */

int split_oper(char *line, char **oper)
{
	char *token;
	int index = 0;

	token = strtok(line, " ");
	while (token != NULL && index < (FILE_SIZE - 1))
	{
		oper[index] = token;
		index++;
		token = strtok(NULL, " ");
	}
	oper[index] = NULL;
	return (index);
}

/**
 * pall - prints the stack nodes.
 * @stack: head pointer of the stack.
 * @line_number: not applyed here.
 */

void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *head = *stack;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

/**
 * free_struct - frees the stack/queue
 * @head: head pointer of the stack/queue.
 */

void free_struct(stack_t *head)
{
	stack_t *next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

/**
 * is_num - checks if a string is a number
 * @num: the number to check.
 * Return: a number.
 */

int is_num(char *num)
{
	int index = 0;

	if (num == NULL)
		return (0);

	while (num[index])
	{
		if (num[index] == '\n')
			num[index] = '\0';
		index++;
	}

	index = 0;
	while (num[index])
	{
		if (num[index] != '-' && (num[index] < '0' || num[index] > '9'))
			return (0);
		index++;
	}

	return (1);
}

/**
 * div - divides the second top element of the stack
 *	by the top element of the stack.
 * @stack: pointer to a node.
 * @line_number: int var - line number of node.
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *next;
	char msg[1024];
	int res = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		sprintf(msg, "L%u: can't div, stack too short", line_number + 1);
		error(msg, *stack, EXIT_FAILURE);
	}
	
	if (head->n == 0)
	{
		sprintf(msg, "L%u: division by zero", line_number + 1);
		error(msg, *stack, EXIT_FAILURE);
	}

	res = head->next->n / head->n;
	head->n = res;
	next = head->next;
	head->next = head->next->next;
	free(next);
}
