
#include "monty.h"
/**
 * push - push data into the stack
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 */
void push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (head == NULL)
	{
		head = *stack;
	}
	else
	{
		head->prev = *stack;
		(*stack)->next = head;
		head = *stack;
	}
}
/**
 * pall - prints data of the doubly linked list
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	(void)stack;
	(void)line_number;
	if (head == NULL)
		printf("%d\n", head->n);
	else
	{
		temp = head;
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
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
