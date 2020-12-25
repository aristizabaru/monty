#include "monty.h"
/**
 * get_fileName - gets the file name within a path
 * @path: string representation of a path
 * Return: the file name
 */
void get_fileName(char *path)
{
	char *file_name = NULL;
	int length = strlen(path);
	int i = length;
	int length_file = 0;

	for (--i; i >= 0; i--)
		if (path[i] == '/')
			break;
	length_file = length - i;
	file_name = malloc(length_file * sizeof(*file_name));
	if (file_name == NULL)
		error_malloc();
	monty_data.free_memory[0] = file_name;
	length = i + 1;
	for (i = 0; i < length_file - 1; i++, length++)
	{
		file_name[i] = path[length];
	}
	file_name[i] = '\0';
	monty_data.file_name = file_name;
}

/**
 * get_lineCount - counts the lines in a file
 * @string: a single buffer with all the info
 * Description: the lines ends with \n
 * Return: number of lines
 */
unsigned int get_lineCount(char *string)
{
	int lines = 0;
	int i = 0;

	if (string)
	{
		for (; string[i]; i++)
		{
			if (string[i] == '\n')
				lines++;
		}
		lines++;
	}

	return (lines);
}

/**
 * cmp_code - compares two opcodes
 * @real_opcode: real opcode
 * @opcode: opcode
 *
 * Return: SUCCESS if match, FAIL if there's not a match
 */
int cmp_code(char *real_opcode, char *opcode)
{
	int i = 0;

	for (; real_opcode[i]; i++)
	{
		if (opcode[i])
		{
			if (real_opcode[i] != opcode[i])
				return (FAILURE);
		}
		else
			return (FAILURE);
	}
	if (opcode[i])
		return (FAILURE);
	return (SUCCESS);
}

/**
 * check_int - checks if a string is an int
 * @str: string to be analize
 * Return: SUCCESS or FAILURE
 */
int check_int(char *str)
{
	int i = 0;
	int result = FAILURE;

	if (str)
		for (; str[i]; i++)
		{
			if (str[i] >= 48 && str[i] <= 57)
				result = SUCCESS;
			else
				result = FAILURE;
		}
	return (result);
}

/**
 * skip_line - skips a line in a array
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
