#include "monty.h"

/**
 * monty_mod -> .putes the rest of the division of the second top element of
 * the stack by the top element of the stack
 * @head: the head of the linked list
 * @counter: the current line in the given file
 * Return: void
 */

void monty_mod(stack_t **head, unsigned int counter)
{
	stack_t *temp, *current = *head;
	int value1, value2;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(file_parameters.file);
		free(file_parameters.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (current->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", counter);
			fclose(file_parameters.file);
			free(file_parameters.content);
			free_stack(*head);
			exit(EXIT_FAILURE);

		}
		else
		{
			temp = current->next;
			value1 = current->n;
			value2 = temp->n;
			temp->n = value2 % value1;
			*head = temp;
			free(current);
		}
	}
}

/**
 * monty_pchar -> prints the char at the top of the stack,
 * followed by a new line.
 * @head: the head of the linked list
 * @counter: the current line in the given file
 * Return: void
 */

void monty_pchar(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;

	if (!current)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(file_parameters.file);
		free(file_parameters.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (current->n < 0 || current->n > 127)
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
			fclose(file_parameters.file);
			free(file_parameters.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
		else
			printf("%c\n", current->n);
	}
}

/**
 * monty_pstr -> prints the string starting at the
 * top of the stack, followed by a new line
 * @head: the head of the linked list
 * @counter: the current line in the given file
 * Return: void
 */

void monty_pstr(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;
	(void) counter;

	if (current == NULL)
		printf("\n");
	else
	{

		while ((current->n > 0 && current->n <= 127) && current->next != NULL)
		{
			printf("%c", current->n);
			current = current->next;
		}
		printf("\n");
	}
}


/**
 * monty_rotl -> rotates the stack to the top
 * @head: the head of the linked list
 * @counter: the current line in the given file
 * Return: void
 */

void monty_rotl(stack_t **head, unsigned int counter)
{
	stack_t *temp, *current = *head;
	(void) counter;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	while (current->next)
	{
		current = current->next;
	}

	temp = (*head)->next;
	temp->prev = NULL;
	current->next = (*head);
	(*head)->prev = current;
	(*head)->next = NULL;
	(*head) = temp;
}

/**
 * monty_rotr -> rotates the stack to the bottom.
 * @head: the head of the linked list
 * @counter: the current line in the given file
 * Return: void
 */

void monty_rotr(stack_t **head, unsigned int counter)
{
	stack_t *temp, *current = *head;
	(void) counter;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	while (current->next)
	{
		current = current->next;
	}

	temp = current->prev;
	temp->next = NULL;

	current->prev = NULL;
	current->next = (*head);
	(*head)->prev = current;

	*head = current;
}
