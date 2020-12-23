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
 * error_push- prints PUSH error message and exit program
 */
void error_pint(void)
{
        fprintf(stderr, "L%d: can't pint, stack empty\n", monty_data.current_line);
        free_all();
        free_stack();
        exit(EXIT_FAILURE);
}