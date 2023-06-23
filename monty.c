#include "monty.h"

int run_command(char *command_line, stack_t **stack,
unsigned int counter, FILE * file_ptr);

file_t file_parameters = {NULL, NULL, NULL, 0};

/**
 * main -> this is the program starting point
 * @ac: this the total arguement count
 * @av: this is the list of arguments
 * Return: int 0 on success
 */

int main(int ac, char **av)
{
	FILE *file_ptr;
	ssize_t lines = 1;
	size_t lines_size = 0;
	char *command_line_ptr;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_ptr = fopen(av[1], "r");
	file_parameters.file = file_ptr;

	if (file_parameters.file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (lines > 0)
	{
		command_line_ptr = NULL;
		lines = getline(&command_line_ptr, &lines_size, file_ptr);
		file_parameters.content = command_line_ptr;
		counter++;
		if (lines > 0)
		{
			run_command(command_line_ptr, &stack, counter, file_ptr);
		}
		free(command_line_ptr);
	}

	free_stack(stack);
	fclose(file_ptr);

	return (0);
}

/**
 * run_command -> this function execute the bettcode
 * command
 * @command_line: this is the give command line
 * @stack: this is the stack linked list
 * @counter: this to locate a command from list of
 * commands
 * @file_ptr: this is the file pointer
 * Return: int 0 on success 1 on failure
 */

int run_command(char *command_line, stack_t **stack,
		unsigned int counter, FILE *file_ptr)
{
	unsigned int index = 0;
	char *command_token;

	instruction_t monty_commands[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{NULL, NULL}
	};

	command_token = strtok(command_line, " \n\t");
	if (command_token && command_token[0] == '#')
		return (0);
	file_parameters.command = strtok(NULL, " \n\t");


	while (monty_commands[index].opcode && command_token)
	{
		if (strcmp(command_token, monty_commands[index].opcode) == 0)
		{
			monty_commands[index].f(stack, counter);
			return (0);
		}
		index++;
	}

	if (command_token && !monty_commands[index].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, command_token);
		fclose(file_ptr);
		free(command_line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}

