#include "monty.h"
/**
 * mod - remainder of the second top element of the stack by the top element
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 */
void mod(stack_t **stack, unsigned int line_number)
{
        stack_t *head = monty_data.head;

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
