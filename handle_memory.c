#include "monty.h"

/**
 * free_stack - frees a dlistint_t list
 *
 * @head: head of the list
 * Return: no return
 */
void free_stack(stack_t *head)
{
	stack_t *current;

	if (head == NULL)
		free(head);
	else
	{
		while (head->next)
		{
			current = head;
			head = head->next;
			free(current);
		}
		free(head);
	}
}
