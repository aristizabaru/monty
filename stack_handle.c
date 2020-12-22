
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
	if (head)
	{
		if (head->next == NULL)
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
}
/**
 * pall - prints data of the doubly linked list
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	if (head == NULL)
	{
		print_error(PINT, NULL, (int)line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", head->n);
}
/**
 * pop - removes the top element of the stack.
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 */
void pop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	if (head == NULL)
	{
		print_error(POP, NULL, (int)line_number);
		exit(EXIT_FAILURE);
	}
	else if (head->next == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		head = head->next;
		free(head->prev);
		head->prev = NULL;
	}
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	(void)stack;
	if (head == NULL || head->next == NULL)
	{
		print_error(SWAP, NULL, (int)line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = head->next->next;
		temp->prev = head;
		head->next->next = head;
		head->next->prev = NULL;
		head->prev = head->next;
		head->next = temp;
		head = head->prev;
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
