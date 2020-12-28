#include "monty.h"
/**
 * free_stack - free the nodes of the doubly linked list
 */
void free_stack(void)
{
	stack_t *head = monty_data.head;

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

/**
 * push - push data into the stack
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *head = monty_data.head;
	stack_t *temp = NULL;

	(void)line_number;
	monty_data.current_opcode_int = get_opcode();
	if (check_int(monty_data.current_opcode_int) == FAILURE)
	{
		free(monty_data.current_opcode_int);
		error_push();
	}
	(*stack)->n = atoi(monty_data.current_opcode_int);
	free(monty_data.current_opcode_int);

	if (head == NULL)
		head = *stack;
	else
	{
		switch (monty_data.behavior)
		{
		case STACK:
			head->prev = *stack;
			(*stack)->next = head;
			head = *stack;
			break;

		case QUEUE:
			temp = head;
			while (temp->next)
				temp = temp->next;
			temp->next = *stack;
			(*stack)->prev = temp;
			break;
		}
	}
	monty_data.head = head;
}

/**
 * pall - prints data of the doubly linked list
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	stack_t *head = monty_data.head;

	(void)line_number;
	if (stack)
		free(*stack);
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
 * pint - prints the value at the top of the stack
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = monty_data.head;

	(void)line_number;
	if (stack)
		free(*stack);
	if (head)
		printf("%d\n", head->n);
	else
		error_pint();
}

/**
 * pop - removes the top element of the stack
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head = monty_data.head;
	stack_t *temp = NULL;

	(void)line_number;
	if (stack)
		free(*stack);
	if (!head)
		error_pop();
	else if (head->next == NULL)
	{
		free(head);
		monty_data.head = NULL;
	}
	else
	{

		temp = head->next;
		free(head);
		temp->prev = NULL;
		head = temp;
		monty_data.head = head;
	}
}
