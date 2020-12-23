#include "monty.h"

/**
 * error_usage - prints USAGE error message and exit program
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	free_all();
	free_stack();
	exit(EXIT_FAILURE);
}
/**
 * error_malloc- prints MALLOC error message and exit program
 */
void error_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_all();
	free_stack();
	exit(EXIT_FAILURE);
}
/**
 * error_open- prints OPEN error message and exit program
 */
void error_open(void)
{
	fprintf(stderr, "Error: Can't open file %s\n", monty_data.file_name);
	free_all();
	free_stack();
	exit(EXIT_FAILURE);
}
/**
 * error_read - prints READ error message and exit program
 */
void error_read(void)
{
	fprintf(stderr, "Error: Can't read file %s\n", monty_data.file_name);
	free_all();
	free_stack();
	exit(EXIT_FAILURE);
}
/**
 * error_opcode - prints OPCODE error message and exit program
 */
void error_opcode(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
		monty_data.current_line, monty_data.current_opcode);
	free_all();
	free_stack();
	exit(EXIT_FAILURE);
}
