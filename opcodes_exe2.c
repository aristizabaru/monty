#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
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
	if (stack)
		free(*stack);
	if (!head || !head->next)
		error_swap();
	else if (!head->next->next)
	{
		temp_left = head;
		temp_right = head->next;
		head = temp_right;
		temp_left->prev = head;
		temp_left->next = NULL;
		temp_right->prev = NULL;
		temp_right->next = temp_left;
	}
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
	}
	monty_data.head = head;
}

/**
 * add - adds the top two elements of the stack
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head = monty_data.head;

	if (stack)
		free(*stack);
	if (!head || !head->next)
		error_add();
	else
	{
		head->next->n += head->n;
		pop(NULL, line_number);
	}
}

/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *head = monty_data.head;

	if (stack)
		free(*stack);
	if (!head || !head->next)
		error_sub();
	else
	{
		head->next->n -= head->n;
		pop(NULL, line_number);
	}
}

/**
 * divi - divides the second top element of the stack by the top element
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 */
void divi(stack_t **stack, unsigned int line_number)
{
	stack_t *head = monty_data.head;

	if (stack)
		free(*stack);
	if (!head || !head->next)
		error_divi(SHORT_STACK);
	else if (head->n == 0)
		error_divi(DIV_BY_0);
	else
	{
		head->next->n /= head->n;
		pop(NULL, line_number);
	}
}

/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *head = monty_data.head;

	if (stack)
		free(*stack);
	if (!head || !head->next)
		error_mul();
	else
	{
		head->next->n *= head->n;
		pop(NULL, line_number);
	}
}
