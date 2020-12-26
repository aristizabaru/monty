#include "monty.h"
/**
 * mod - remainder of the second top element of the stack by the top element
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 */
void mod(stack_t **stack, unsigned int line_number)
{
        stack_t *head = monty_data.head;

        free(*stack);
        if (!head || !head->next)
                error_mod(SHORT_STACK);
        else if (head->n == 0)
                error_mod(DIV_BY_0);
        else
        {
                head->next->n %= head->n;
                pop(stack, line_number);
        }
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 */
void pchar(stack_t **stack, unsigned int line_number)
{
        stack_t *head = monty_data.head;

        (void)line_number;
        free(*stack);
        if (!head)
                error_pchar(EMPTY_STACK);
        else if (head->n < 32 && head->n > 126)
                error_pchar(OUT_OF_RANGE);
        else
                printf("%c\n", head->n);
}