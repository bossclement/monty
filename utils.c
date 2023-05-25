#include "monty.h"

/**
 * split_lines - prints by new line.
 * @buffer: content of a file.
 * @lines: array of pointers to stores the lines.
 */

void split_lines(char *buffer, char **lines)
{
	char *token;
	int index = 0;

	token = strtok(buffer, "\n");
	while (token != NULL && index < (FILE_SIZE - 1))
	{
		lines[index] = token;
		index++;
		token = strtok(NULL, "\n");
	}
	lines[index] = NULL;
}

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
		if (num[index] != '-' && (num[index] < '0' || num[index] > '9'))
			return (0);
		index++;
	}

	return (1);
}
