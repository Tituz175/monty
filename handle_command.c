#include "monty.h"

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
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
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

/**
 * addqueue -> adds a new node at the end
 * of a dlistint_t list
 *
 * @head: head of the list
 * @n: value of the element
 * Return: the address of the new element
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new, *temp = *head;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (temp == NULL)
		*head = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}

