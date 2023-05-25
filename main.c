#include "monty.h"

void error(char *msg, stack_t *stack, int code);
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
		error("Error: malloc failed", NULL, EXIT_FAILURE);

	new->n = line_number;
	if (*stack)
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

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;
	char msg[1024];

	if (*stack)
	{
		next = (*stack)->next;
		free(*stack);
	} else
	{
		sprintf(msg, "L%u: can't pop an empty stack", line_number);
		error(msg, *stack, EXIT_FAILURE);
	}
	*stack = next;
}

/**
 * find_oper - finds an operation function to use.
 * @oper: the operation to find a function for.
 * Return: Pointer of the function found.
 */

void (*find_oper(char *oper))(stack_t **stack, unsigned int line_number)
{
	int index = 0;
	instruction_t functions[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};


	while (functions[index].opcode && strcmp(functions[index].opcode, oper) != 0)
		index++;
	return (functions[index].f);
}

/**
 * error - prints error and exit the program.
 * @msg: error message to print.
 * @stack: the pointer to the header of the stack.
 * @code: exit code.
 */

void error(char *msg, stack_t *stack, int code)
{
	fprintf(stderr, "%s\n", msg);
	free_struct(stack);
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
	char line[FILE_SIZE], *oper[FILE_SIZE], msg[FILE_SIZE], *ln;
	unsigned int line_index = 0, oper_args;
	void (*oper_func)(stack_t **stack, unsigned int line_number);
	stack_t *stack = NULL;
	FILE *file;

	if (argc != 2)
		error("USAGE: monty file", stack, EXIT_FAILURE);

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		sprintf(msg, "Error: Can't open file %s", argv[1]);
		error(msg, stack, EXIT_FAILURE);
	}


	while (fgets(line, FILE_SIZE, file) != NULL)
	{
		ln = strtok(line, "\n");
		oper_args = split_oper(ln, oper);
		if (oper_args == 0)
		{
			line_index++;
			continue;
		}
		oper_func = find_oper(oper[0]);
		if ((strcmp(oper[0], "push") == 0 && oper_args < 2) ||
		(is_num(oper[1]) == 0 && strcmp(oper[0], "push") == 0))
		{
			sprintf(msg, "L%u: usage: push integer", line_index + 1);
			error(msg, stack, EXIT_FAILURE);
		}
		if (oper_func)
		{
			if (oper_args > 1)
				(*oper_func)(&stack, atoi(oper[1]));
			else if (oper_args == 1)
				(*oper_func)(&stack, line_index);
		}
		else
		{
			sprintf(msg, "L%u: unknown instruction %s", line_index + 1, oper[0]);
			error(msg, stack, EXIT_FAILURE);
		}
		line_index++;
	}
	fclose(file);
	free_struct(stack);
	return (0);
}
