#include "monty.h"
/**
* f_pstr - Pulls string at the beginning of stack
* accompanid by a fresh line
* @head: Beginning of stack
* @counter: Number of lines
* Return: no return
*/

void f_pstr(stack_t **head, unsigned int counter)
{
stack_t *h;
(void)counter;

h = *head;
while (h)
{
if (h->n > 127 || h->n <= 0)
{
break;
}
printf("%c", h->n);
h = h->next;
}
printf("\n");
}
