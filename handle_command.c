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
