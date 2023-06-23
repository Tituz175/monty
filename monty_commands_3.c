#include "monty.h"

/**
 * monty_mod -> computes the rest of the division of the second top element of
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
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
