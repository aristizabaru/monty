#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 */
void swap(stack_t **stack, unsigned int line_number)
{
        stack_t *head = monty_data.head;
        stack_t *temp_middle = NULL;
        stack_t *temp_right = NULL;
        stack_t *temp_left = NULL;

        (void)line_number;
        free(*stack);
        if (!head || !head->next)
                error_swap();
        else
        {
                temp_left = head;
                temp_middle = head->next;
                temp_right = temp_middle->next;
                head = temp_middle;
                head->prev = NULL;
                head->next = temp_left;
                temp_left->prev = head;
                temp_left->next = temp_right;
                temp_right->prev = temp_left;
                monty_data.head = head;
        }
}