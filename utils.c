#include "monty.h"

/**
 * split_lines - prints by new line.
 * @buffer: content of a file
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
