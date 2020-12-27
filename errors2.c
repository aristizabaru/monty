#include "monty.h"
/**
 * error_push- prints PUSH error message and exit program
 */
void error_push(void)
{
	fprintf(stderr, "L%d: usage: push integer\n", monty_data.current_line);
	free_all();
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * error_pint - prints PINT error message and exit program
 */
void error_pint(void)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", monty_data.current_line);
	free_all();
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * error_pop - prints POP error message and exit program
 */
void error_pop(void)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", monty_data.current_line);
	free_all();
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * error_swap - prints SWAP error message and exit program
 */
void error_swap(void)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n",
		monty_data.current_line);
	free_all();
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * error_add - prints ADD error message and exit program
 */
void error_add(void)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", monty_data.current_line);
	free_all();
	free_stack();
	exit(EXIT_FAILURE);
}
