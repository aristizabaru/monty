#include "monty.h"
/**
 * mod - remainder of the second top element of the stack by the top element
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *head = monty_data.head;

	if (stack)
		free(*stack);
	if (!head || !head->next)
		error_mod(SHORT_STACK);
	else if (head->n == 0)
		error_mod(DIV_BY_0);
	else
	{
		head->next->n %= head->n;
		pop(NULL, line_number);
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
	if (stack)
		free(*stack);
	if (!head)
		error_pchar(EMPTY_STACK);
	else if (head->n < 32 || head->n > 126)
		error_pchar(OUT_OF_RANGE);
	else
		printf("%c\n", head->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *head = monty_data.head;
	stack_t *temp = NULL;

	(void)line_number;
	if (stack)
		free(*stack);
	if (!head)
		printf("\n");
	else if (!head->next)
	{
		if (head->n != 0 && (head->n > 31 && head->n < 127))
			printf("%c\n", head->n);
		else
			printf("\n");
	}
	else
	{
		temp = head;
		while (temp && temp->n != 0 && (temp->n > 31 && temp->n < 127))
		{
			printf("%c", temp->n);
			temp = temp->next;
		}
		printf("\n");
	}
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: node of the doubly linked list
 * @line_number: line_number of the execution
 * Description: The last element of the stack becomes the top element of the stack
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *head = monty_data.head;

	(void)line_number;
	if (stack)
		free(*stack);
	if (head)
	{
		if (head->next && !head->next->next)
			head = head->next;
		else if (head->next)
		{
			while (head->next)
				head = head->next;
		}
	}
	monty_data.head = head;
}
