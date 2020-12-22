#include "header.h"
/**
 * get_fileName - gets the file name within a path
 * @path: string representation of a path
 * Return: the file name
 */
char *get_fileName(char *path)
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
	{
		free(path);
		print_error(MALLOC, NULL, 0);
		exit(EXIT_FAILURE);
	}
	length = i + 1;
	for (i = 0; i < length_file - 1; i++, length++)
	{
		file_name[i] = path[length];
	}
	file_name[i] = '\0';
	return (file_name);
}
/**
 * get_lineCount - counts the lines in a file
 * @string: a single buffer with all the info
 * Description: the lines are representate with \n
 * Return: line count
 */
int get_lineCount(char *string)
{
	int lines = 0;
	int i = 0;

	for (; string[i]; i++)
	{
		if (string[i] == '\n')
			lines++;
	}
	return (lines + 1);
}
/**
 * get_lines - divides a string into tokens
 * @file_info: a single buffer with all the info to be tokenizated
 * Return: matrix with tokens
 */
char **get_lines(char *file_info)
{
	char **file_info_lines = NULL;
	char *token = NULL;
	int line_count = 0;
	int i = 0;

	line_count = get_lineCount(file_info);
	file_info_lines = malloc((line_count + 1) * sizeof(token));
	if (file_info_lines == NULL)
	{
		print_error(MALLOC, NULL, 0);
		free(file_info);
		exit(EXIT_FAILURE);
	}
	token = strtok(file_info, "\n");
	while (token != NULL)
	{
		file_info_lines[i] = token;
		token = strtok(NULL, "\n");
		i++;
	}
	file_info_lines[line_count] = NULL;
	return (file_info_lines);
}

/**
 * check_int - checks if a string is an int
 * @str: string to be analize
 * Return: SUCCESS or FAILURE
 */
int check_int(char *str)
{
	int i = 0;

	if (str)
		for (; str[i]; i++)
			if (str[i] >= 48 && str[i] <= 57)
				return (SUCCESS);
	return (FAILURE);
}
