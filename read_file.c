#include "header.h"
/**
 * open_file - opens a file
 * @path: path of the file
 * @file_name: name of the file
 * Return: file descriptor of the file
 */
int open_file(char *path, char *file_name)
{
	int fd_monty = 0;

	fd_monty = open(path, O_RDONLY);
	if (fd_monty == -1)
	{
		print_error(OPEN_FILE, file_name, 0);
		free(file_name);
		exit(EXIT_FAILURE);
	}
	return (fd_monty);
}
/**
 * read_file - read file into a buffer
 * @fd_monty: file descriptor of the file
 * @file_name: name of the file
 * Return: buffer with file info
 */
char *read_file(int fd_monty, char *file_name)
{
	int characters = 0;
	char buffer[BUFFER_SIZE];
	char *file_info = NULL;

	do {
		characters = read(fd_monty, buffer, BUFFER_SIZE);
		if (characters > 0)
			file_info = buffer_to_fileinfo(buffer, file_info, characters);
		if (characters == -1)
		{
			print_error(READ, file_name, 0);
			free(file_name);
			free(file_info);
			exit(EXIT_FAILURE);
		}

	} while (characters > 0);
	free(file_name);
	return (file_info);
}
/**
 * init_buffer - allocate memory for a buffer
 * @buff_size: size of the buffer
 * Return: new buffer
 */
char *init_buffer(int buff_size)
{
	char *buffer = NULL;
	int i = 0;

	buffer = malloc(buff_size * sizeof(*buffer));
	if (buffer == NULL)
	{
		print_error(MALLOC, NULL, 0);
		exit(EXIT_FAILURE);
	}
	for (; i < buff_size; i++)
		buffer[i] = '\0';
	return (buffer);
}
/**
 * buffer_to_fileinfo - copy data from buffer to dynamic array
 * @buffer: the buffer
 * @file_info: the array to be filled
 * @characters: number of character to be filled
 * Return: array filled with data
 */
char *buffer_to_fileinfo(char *buffer, char *file_info, int characters)
{
	char *new_file_info = NULL;
	int length = 0, i = 0;

	if (file_info)
	{
		length = strlen(file_info);
		new_file_info = init_buffer(characters + length + 1);
		while (file_info[i])
		{
			new_file_info[i] = file_info[i];
			i++;
		}
		free(file_info);
	}
	else
		new_file_info = init_buffer(characters + 1);

	i = 0;
	while (i < characters)
	{
		new_file_info[i + length] = buffer[i];
		i++;
	}
	return (new_file_info);
}
