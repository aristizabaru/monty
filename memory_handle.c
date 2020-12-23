#include "monty.h"

/**
 * free_all - free all allocated memory in the program
 */
void free_all(void)
{
	int i;

	for (i = 0; i < ITEMS_TO_FREE; i++)
	{
		if (monty_data.free_memory[i])
		{
			free(monty_data.free_memory[i]);
			monty_data.free_memory[i] = NULL;
		}
	}
}
