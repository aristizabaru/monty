

#include "monty.h"
void add(stack_t **stack, unsigned int line_number)
{
        int result = 0;

        (void)stack;
        if (head == NULL || head->next == NULL)
        {
                print_error(SWAP, NULL, (int)line_number);
                exit(EXIT_FAILURE);
        }
        else
        {
                result = head->n + head->next->n;
                pop(NULL, line_number);
                head->n = result;
        }
}
/**
 * nop - doesn't do anything
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 */
void nop(stack_t **stack, unsigned int line_number)
{
        (void)stack;
        (void)line_number;
}
/**
 * free_stack - free the nodes of the doubly linked list
 */
void free_stack(void)
{
        if (head != NULL)
        {
                while (head->next)
                {
                        head = head->next;
                        free(head->prev);
                }
                free(head);
                head = NULL;
        }
}
