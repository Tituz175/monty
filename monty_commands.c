#include "monty.h"

/**
 * monty_push -> this function add the given number
 * to the linked list
 * @head: the head of the linked list
 * @counter: the current line in the given file
 * Return: void
 */

void monty_push(stack_t **head, unsigned int counter)
{
	int number, index = 0, isNum = 0;


	if (file_parameters.command)
	{
		if (file_parameters.command[0] == '-')
			index++;
		for (; file_parameters.command[index] != '\0'; index++)
		{
			if (file_parameters.command[index] < '0' ||
					file_parameters.command[index] > '9')
				isNum = 1;
		}

		if (isNum == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(file_parameters.file);
			free(file_parameters.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}

	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(file_parameters.file);
		free(file_parameters.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	number = atoi(file_parameters.command);
	if (file_parameters.flag == 0)
	{
		addnode(head, number);
	}
}

/**
 * monty_pall -> this function prints a linked list
 * @head: the head of the linked list
 * @counter: unuse parameter
 * Return: void
 */

void monty_pall(stack_t **head, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	current = *head;

	if (!current)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}

}
