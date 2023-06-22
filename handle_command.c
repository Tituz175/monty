#include "monty.h"

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
		printf("In run_command\n");
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, command_token);
		fclose(file_ptr);
		free(command_line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}

/**
 * addnode -> this function add a new node
 * at the head of the list
 * @head: the head of the list
 * @n: the give number
 * Return: the address of the added new
 */

void addnode(stack_t **head, int n)
{
	stack_t *new_node, *temp = *head;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (temp == NULL)
		*head = new_node;
	else
	{
		temp->prev = new_node;
		new_node->next = temp;
		*head = new_node;
	}
}
