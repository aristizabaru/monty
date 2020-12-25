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
