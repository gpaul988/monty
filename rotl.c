#include "monty.h"
/**
*f_rotl- Recycles stack to the beginning
*@head: Beginning of stack
*@counter: Number of lines
*Return: no return
*/

void f_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
stack_t *tmp = *head, *aux;

if (*head == NULL || (*head)->next == NULL)
{
return;
}
aux = (*head)->next;
aux->prev = NULL;
while (tmp->next != NULL)
{
tmp = tmp->next;
}
tmp->next = *head;
(*head)->next = NULL;
(*head)->prev = tmp;
(*head) = aux;
}
