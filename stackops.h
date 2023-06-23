#include "monty.h"
/**
 * f_mod - Determine the division of second best part
 * of stack by the bets part of stack
 * @head: Beaginnin of stack
 * @counter: Number of lines
 * Return: no return
 */

void f_mod(stack_t **head, unsigned int counter)
{
    stack_t *h;
    int len = 0, aux;

    h = *head;
    while (h)
    {
        h = h->next;
        len++;
    }
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    h = *head;
    if (h->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    aux = h->next->n % h->n;
    h->next->n = aux;
    *head = h->next;
    free(h);
}

/**
 * f_pchar - Pulls char at the beginning of stack,
 * next to a fresh line
 * @head: Beginning of stack
 * @counter: Number of lines
 * Return: no return
 */
void f_pchar(stack_t **head, unsigned int counter)
{
    stack_t *h;

    h = *head;
    if (!h)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    if (h->n > 127 || h->n < 0)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    printf("%c\n", h->n);
}

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

/**
 *f_rotr- Recycles stack to the bottom
 *@head: Beginning of stack
 *@counter: Number of lines
 *Return: no return
 */

void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    stack_t *copy;

    copy = *head;
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    while (copy->next)
    {
        copy = copy->next;
    }
    copy->next = *head;
    copy->prev->next = NULL;
    copy->prev = NULL;
    (*head)->prev = copy;
    (*head) = copy;
}