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

/**
 * monty_pint -> this function prints the top value of a linked list
 * @head: the head of the linked list
 * @counter: the current line in the given file
 * Return: void
 */

void monty_pint(stack_t **head, unsigned int counter)
{
	stack_t *current;

	current = *head;

	if (!current)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
		fclose(file_parameters.file);
		free(file_parameters.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", current->n);

}


/**
 * monty_pop -> this function prints the element at the top of a linked list
 * @head: the head of the linked list
 * @counter: the current line in the given file
 * Return: void
 */

void monty_pop(stack_t **head, unsigned int counter)
{
	stack_t *current;

	current = *head;

	if (!current)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(file_parameters.file);
		free(file_parameters.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		*head = current->next;
		free(current);
	}
}

/**
 * monty_swap -> swaps the top two elements of the stack
 * @head: the head of the linked list
 * @counter: the current line in the given file
 * Return: void
 */

void monty_swap(stack_t **head, unsigned int counter)
{
	stack_t *temp, *current = *head;
	int value;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(file_parameters.file);
		free(file_parameters.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = current->next;
		value = current->n;
		current->n = temp->n;
		temp->n = value;
	}
}
