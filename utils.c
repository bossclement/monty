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
