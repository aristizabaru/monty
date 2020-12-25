#include "monty.h"
/**
 * open_file - opens a file
 * @path: path of the file
 * Return: file descriptor of the file
 */
unsigned int open_file(char *path)
{
	int fd_monty = 0;

	fd_monty = open(path, O_RDONLY);
	if (fd_monty == -1)
		error_open();
	return (fd_monty);
}

/**
 * read_file - read file and pass it to an a buffer array
 * @fd_monty: file descriptor of the file
 * Return: buffer with file info
 */
char *read_file(unsigned int fd_monty)
{
	int characters = 0;
	char buffer[BUFFER_SIZE];
	char *raw_data = NULL;

	do {
		characters = read(fd_monty, buffer, BUFFER_SIZE);
		if (characters > 0)
			raw_data = copy_data(buffer, raw_data, characters);
		if (characters == -1 || (characters == 0 && !raw_data))
		{
			if (raw_data)
				free(raw_data);
			close(fd_monty);
			error_read();
		}

	} while (characters > 0);
	monty_data.free_memory[1] = raw_data;
	monty_data.file_data = raw_data;
	return (raw_data);
}
/**
 * copy_data - copy data from buffer to array
 * @buffer: the buffer with the data
 * @data: the array where the information will be sent
 * @characters: number of character to be copied
 * Return: array with data from buffer
 */
char *copy_data(char *buffer, char *data, int characters)
{
	char *new_data = NULL;
	int length = 0, i = 0;

	/* copy what is in data already */
	if (data)
	{
		length = strlen(data);
		new_data = allocate_memory(characters + length + 1);
		while (data[i])
		{
			new_data[i] = data[i];
			i++;
		}
		free(data);
	}
	else
		new_data = allocate_memory(characters + 1);

	/* copy what is in buffer*/
	i = 0;
	while (i < characters)
	{
		new_data[i + length] = buffer[i];
		i++;
	}
	return (new_data);
}

/**
 * allocate_memory - allocate memory
 * @size: size of the memory to be allocated
 * Return: string with memory allocated
 */
char *allocate_memory(int size)
{
	char *new_size = NULL;
	int i = 0;

	new_size = malloc(size * sizeof(*new_size));
	if (new_size == NULL)
		error_malloc();
	for (; i < size; i++)
		new_size[i] = '\0';
	return (new_size);
}
