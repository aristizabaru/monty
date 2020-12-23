#include "monty.h"
/**
 * skip_line - skips a line in a array
 * @array: data to skipe the line
 * Description: the end of line is '\n'
 */
void skip_line(void)
{
        unsigned int idx = monty_data.data_index;

        for (; monty_data.file_data[idx] && monty_data.file_data[idx] != '\n'; idx++)
                ;
        if (monty_data.file_data[idx])
                monty_data.data_index = idx + 1;
}