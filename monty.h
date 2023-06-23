#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/uio.h>
#define BUFSIZE 1024
extern FILE *file;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
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
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


void (*search(char *op_f, unsigned int l, stack_t **s))(stack_t**, unsigned int);
void _push(stack_t **stack, unsigned int line_number, char *temp);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);

void _freestack(stack_t *stack);
int _isdigit(char *str);


void *_memcpy(void *dest, const void *src, size_t n);
void *_realloc(void *ptr, size_t old_size, size_t size);

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _fileno(FILE *stream);

#endif /**MONTY_H*/

