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
	/*stack_t *current = *head;*/

	if ((*head) == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(file_parameters.file);
		free(file_parameters.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((*head)->next->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", counter);
			fclose(file_parameters.file);
			free(file_parameters.content);
			free_stack(*head);
			exit(EXIT_FAILURE);

		}
		else
		{
			(*head)->next->next->n %= (*head)->next->n;
			monty_pop(head, counter);
		}
	}
}
