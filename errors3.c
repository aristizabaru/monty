#include "monty.h"
/**
 * error_sub - prints SUB error message and exit program
 */
void error_sub(void)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", monty_data.current_line);
	free_all();
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * error_divi - prints DIVI error message and exit program
 * @code: code of message error
 */
void error_divi(int code)
{
	switch (code)
	{
	case SHORT_STACK:
		fprintf(stderr, "L%d: can't div, stack too short\n",
			monty_data.current_line);
		break;
	case DIV_BY_0:
		fprintf(stderr, "L%d: division by zero\n", monty_data.current_line);
		break;
	default:
		break;
	}
	free_all();
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * error_mul - prints MUL error message and exit program
 */
void error_mul(void)
{
	fprintf(stderr, "L%d: can't mul, stack too short\n", monty_data.current_line);
	free_all();
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * error_mod - prints MOD error message and exit program
 * @code: code of message error
 */
void error_mod(int code)
{
	switch (code)
	{
	case SHORT_STACK:
		fprintf(stderr, "L%d: can't mod, stack too short\n",
			monty_data.current_line);
		break;
	case DIV_BY_0:
		fprintf(stderr, "L%d: division by zero\n", monty_data.current_line);
		break;
	default:
		break;
	}
	free_all();
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * error_pchar - prints PCHAR error message and exit program
 * @code: code of message error
 */
void error_pchar(int code)
{
	switch (code)
	{
	case EMPTY_STACK:
		fprintf(stderr, "L%d: can't pchar, stack empty\n", monty_data.current_line);
		break;
	case OUT_OF_RANGE:
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
			monty_data.current_line);
		break;
	default:
		break;
	}
	free_all();
	free_stack();
	exit(EXIT_FAILURE);
}
