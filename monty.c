#include "monty.h"
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
