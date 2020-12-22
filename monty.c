#include "monty.h"
stack_t *head = NULL; /* global variable for stack control */

/**
 * main - entry point to monty program
 * @argc: arguments count
 * @argv: arguments values
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	int fd_monty = 0;
	char *path = argv[1];
	char *file_name = NULL;
	char *file_info = NULL;
	char **file_info_lines = NULL;
	instruction_t opcodes[] = {
	    {"push", push},
	    {"pall", pall},
	    {"pint", pint},
	    {"pop", pop},
	    {"swap", swap},
	    {NULL, NULL}};

	if (argc != 2)
		print_error(USAGE, NULL, 0);
	file_name = get_fileName(argv[1]);
	fd_monty = open_file(path, file_name);
	file_info = read_file(fd_monty, file_name);
	file_info_lines = get_lines(file_info);
	if (analyze_op(file_info_lines, opcodes, file_info) == FAILURE)
	{
		close(fd_monty);
		exit(EXIT_FAILURE);
	}
	close(fd_monty);
	free_stack();
	return (EXIT_SUCCESS);
}
