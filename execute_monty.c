#include "monty.h"

/**
 * exucute_monty - read lines of file .m and execute codes
 */
void exucute_monty(void)
{
	unsigned int lines = monty_data.lines_total;
	/* unsigned int lines = 1; */
	unsigned int current_line = 1;

	monty_data.data_index = 0;
	for (; lines > 0; lines--, current_line++)
	{
		monty_data.current_line = current_line;
		if (monty_data.current_opcode)
			free(monty_data.current_opcode);
		monty_data.current_opcode = get_opcode();
		monty_data.free_memory[2] = monty_data.current_opcode;
		if (monty_data.current_opcode == NULL || monty_data.current_opcode[0] == '#')
		{
			skip_line();
			continue;
		}
		execute_opcode();
		skip_line();
	}
}
/**
 * execute_opcode - send order to execute opcode
 */
void execute_opcode(void)
{
	int opcode_idx = -1;
	stack_t *new_node = NULL;

	opcode_idx = get_opcode_idx();
	/* check error in opcode */
	if (opcode_idx == -1)
		error_opcode();
	/* check if opcode is "nop"*/
	if (opcode_idx == 6)
		return;
	/* check for "stack" or "queue" */
	if (opcode_idx == 15)
	{
		monty_data.behavior = STACK;
		return;
	}
	else if (opcode_idx == 16)
	{
		monty_data.behavior = QUEUE;
		return;
	}
	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		error_malloc();
	new_node->next = NULL;
	new_node->prev = NULL;
	/* call opcode exec */
	monty_data.opcodes_list[opcode_idx].f(&new_node, monty_data.current_line);
}
/**
 * get_opcode_idx - get index of opcode to execute in array of opcodes
 * Return: index number of opcode in list
 */
int get_opcode_idx(void)
{
	int i = 0;
	int index = -1;

	for (; monty_data.opcodes_list[i].opcode; i++)
	{
		if (cmp_code(monty_data.opcodes_list[i].opcode,
			     monty_data.current_opcode) == SUCCESS)
		{
			index = i;
			return (index);
		}
	}
	return (index);
}
/**
 * get_opcode - get the opcode from a line in a file
 * Return: string with opcode
 */
char *get_opcode(void)
{
	char *opcode = NULL;
	unsigned int idx = monty_data.data_index;
	unsigned int firts_idx = 0;
	unsigned int last_idx = 0;
	char c;

	for (; monty_data.file_data[idx]; idx++)
	{
		c = monty_data.file_data[idx];
		if (c != ' ' && c != '\n')
		{
			firts_idx = idx;
			for (; monty_data.file_data[idx]; idx++)
			{
				c = monty_data.file_data[idx];
				if (c == ' ' || c == '\n' || monty_data.file_data[idx + 1] == '\0')
				{
					last_idx = idx;
					/* takes the last char of a file if there is EOF */
					if (monty_data.file_data[idx + 1] == '\0' && c != ' ' && c != '\n')
						last_idx += 1;
					monty_data.data_index = last_idx;
					opcode = copy_opcode(firts_idx, last_idx);
					return (opcode);
				}
			}
		}
		else if (c == '\n' || monty_data.file_data[idx + 1] == '\0')
			break;
	}
	return (opcode);
}
/**
 * copy_opcode - copy opcode to a new string
 * @firts_idx: the starting index to copy from a string
 * @last_idx: the last index to copy from a string
 * Return: new string with opcode
 */
char *copy_opcode(unsigned int firts_idx, unsigned int last_idx)
{
	unsigned int idx = firts_idx;
	unsigned int size = last_idx - firts_idx;
	char *opcode = NULL;
	unsigned int i = 0;

	opcode = malloc((size + 1) * sizeof(*opcode));
	for (; idx < last_idx; idx++, i++)
		opcode[i] = monty_data.file_data[idx];
	opcode[i] = '\0';

	return (opcode);
}
