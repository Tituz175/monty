#ifndef MAIN_H
#define MAIN_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct file_s -> struct for all the needful details
 * of a given file
 * @file: the file pointer
 * @content: the content of the file
 * @command: the command in the file
 * @flag: to indicate stack or queue
 *
 * Description: Files and the important details
 */

typedef struct file_s
{
	FILE *file;
	char *command;
	char *content;
	int flag;
} file_t;
extern file_t file_parameters;

void free_stack(stack_t *head);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void monty_push(stack_t **head, unsigned int counter);
void monty_pall(stack_t **head, unsigned int counter);
void monty_pint(stack_t **head, unsigned int counter);
void monty_pop(stack_t **head, unsigned int counter);
void monty_swap(stack_t **head, unsigned int counter);
void monty_add(stack_t **head, unsigned int counter);
void monty_nop(stack_t **head, unsigned int counter);
void monty_sub(stack_t **head, unsigned int counter);
void monty_div(stack_t **head, unsigned int counter);
void monty_mul(stack_t **head, unsigned int counter);
void monty_mod(stack_t **head, unsigned int counter);
void monty_pchar(stack_t **head, unsigned int counter);
void monty_pstr(stack_t **head, unsigned int counter);
void monty_rotl(stack_t **head, unsigned int counter);
void monty_rotr(stack_t **head, unsigned int counter);
void monty_stack(stack_t **head, unsigned int counter);
void monty_queue(stack_t **head, unsigned int counter);

#endif
