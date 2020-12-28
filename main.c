#include "monty.h"
global_t monty_data;

/**
 * main - entry point to monty program
 * @argc: arguments count
 * @argv: arguments values
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	char *path = argv[1];
	unsigned int fd_monty = 0;

	monty_data.head = NULL;
	monty_data.behavior = STACK;
	init_opcodes();
	if (argc != 2)
		error_usage();
	get_fileName(argv[1]);
	fd_monty = open_file(path);
	read_file(fd_monty);
	close(fd_monty);
	monty_data.lines_total = get_lineCount(monty_data.file_data);
	exucute_monty();
	free_all();
	free_stack();
	return (EXIT_SUCCESS);
}
