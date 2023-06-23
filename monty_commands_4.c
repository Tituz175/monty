#include "monty.h"

/**
 * monty_queue -> flags 1 if it is a queue
 * @head: the head of the linked list
 * @counter: the current line in the given file
 * Return: void
 */

void monty_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	file_parameters.flag = 1;
}

/**
 * monty_stack -> flags 0 if it is a stack
 * @head: the head of the linked list
 * @counter: the current line in the given file
 * Return: void
 */

void monty_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	file_parameters.flag = 0;
}
