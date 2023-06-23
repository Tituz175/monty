#include "monty.h"

/**
 * monty_add -> adds the top two elements of the stack
 * remove the top two elements of the stack and make their
 * sum the top element of the stack
 * @head: the head of the linked list
 * @counter: the current line in the given file
 * Return: void
 */

void monty_add(stack_t **head, unsigned int counter)
{
	stack_t *temp, *current = *head;
	int value1, value2;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
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
		temp->n = value1 + value2;
		*head = temp;
		free(current);
	}
}

/**
 * monty_nop -> just here for no reason
 * @head: the head of the linked list
 * @counter: unuse parameter
 * Return: void
 */

void monty_nop(stack_t **head, unsigned int counter)
{
	(void)counter;
	(void)head;
}

/**
 * monty_sub -> subtracts the top element of the stack
 * from the second top element of the stack
 * @head: the head of the linked list
 * @counter: the current line in the given file
 * Return: void
 */

void monty_sub(stack_t **head, unsigned int counter)
{
	stack_t *temp, *current = *head;
	int value1, value2;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
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
		temp->n = value2 - value1;
		*head = temp;
		free(current);
	}
}

/**
 * monty_div -> divides the second top element of the
 * stack by the top element of the stack
 * @head: the head of the linked list
 * @counter: the current line in the given file
 * Return: void
 */

void monty_div(stack_t **head, unsigned int counter)
{
	stack_t *temp, *current = *head;
	int value1, value2;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
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
			temp->n = value2 / value1;
			*head = temp;
			free(current);
		}
	}
}

/**
 * monty_mul -> multiplies the second top element of the
 * stack with the top element of the stack
 * @head: the head of the linked list
 * @counter: the current line in the given file
 * Return: void
 */

void monty_mul(stack_t **head, unsigned int counter)
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
		temp->n = value2 * value1;
		*head = temp;
		free(current);
	}
}
