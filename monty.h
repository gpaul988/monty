#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - Multiple connected list depiction of stack/mound
 * @n: integer
 * @prev: Directs to past element of stack/mound
 * @next: Directs to next element of stack/mound
 *
 * Description: Multiple connected list node shape
 * for stack, mound, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct bus_s - Modifiable -args, file, line content
 * @arg: Worth
 * @file: Directs to monty file
 * @content: line detail
 * @lifi: Shows changes stack <-> queue
 * Description: Holds worth through the program
 */

typedef struct bus_s
{
    char *arg;
    FILE *file;
    char *content;
    int lifi;
} bus_t;
extern bus_t bus;

/**
 * struct instruction_s - opcode and its purpose
 * @opcode: Opcode
 * @f: Purpose to solve the opcode
 *
 * Description: opcode and its purpose
 * for stack, mound, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
ssize_t getstdin(char **lineptr, int file);
char *clean_line(char *content);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void f_push(stack_t **head, unsigned int number);
void f_pall(stack_t **head, unsigned int number);
void f_pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void f_mul(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);
void f_pchar(stack_t **head, unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);
void f_rotl(stack_t **head, unsigned int counter);
void f_pop(stack_t **head, unsigned int counter);
void f_swap(stack_t **head, unsigned int counter);
void f_add(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);
void f_div(stack_t **head, unsigned int counter);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int counter);
void f_stack(stack_t **head, unsigned int counter);
#endif
