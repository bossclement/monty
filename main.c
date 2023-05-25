#include "monty.h"

void error(char *msg, int code);
void push(stack_t **stack, unsigned int line_number);
void (*find_oper(char *oper))(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

/**
 * push - adds an element in the list
 * @stack: point to a node
 * @line_number: number of the new node
 */
 
 void push(stack_t **stack, unsigned int line_number)
 {
 	stack_t *new = (stack_t *)malloc(sizeof(stack_t));
 
 	if (new == NULL)
 		error("Error: malloc failed", EXIT_FAILURE);
 		
 	new->n = line_number;
 	new->prev = (*stack)->prev;
 	new->next = *stack;
 	
 	if (*stack)
 		(*stack)->prev = new;
 	
 	*stack = new;
 }
 
 /**
 * pop - removes an element in the list
 * @stack: point to a node
 * @line_number: number of the new node
 */
 
void pop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *next = NULL;

	if (*stack)
	{
		next = (*stack)->next;
		free(*stack);
	}
	*stack = next;
}

/**
 * error - prints error and exit the program
 * @msg: error message to print
 * @code: exit code
 */

void (*find_oper(char *oper))(stack_t **stack, unsigned int line_number)
{
	int index = 0;

	instruction_t functions[] = {
		{"push", push},
		{"pop", pop},
		{NULL, NULL}
	};
	
	while (functions[index].opcode && !strcmp(functions[index].opcode, oper))
		index++;
	return (functions[index].f);
}

/**
 * error - prints error and exit the program
 * @msg: error message to print
 * @code: exit code
 */

void error(char *msg, int code)
{
	fprintf(stderr, "%s\n", msg);
	exit(code);
}


/**
 * main - main function of the program
 * @argc: number of arguments of the program
 * @argv: list arguments passed in the program
 * Return: Allways 0
 */

int main(int argc, char **argv __attribute__((unused)))
{
	char buffer[FILE_SIZE], **lines[FILE_SIZE];
	size_t nread;
	FILE *file;

	if (argc != 2)
		error("USAGE: monty file", EXIT_FAILURE);

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		sprintf(buffer, "Error: Can't open file %s", argv[1]);
		error(buffer, EXIT_FAILURE);
	}
	
	nread = fread(buffer, sizeof(char), FILE_SIZE - 1, file);
	if (nread > 0)
		buffer[nread] = '\0';
	else
	{
		sprintf(buffer, "Error: Can't open file %s", argv[1]);
		error(buffer, EXIT_FAILURE);
	}
	return (0);
}
