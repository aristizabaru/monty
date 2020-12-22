#include "monty.h"
/**
 * analyze_op - analize opcode to execute it
 * @file_info_lines: the data in lines
 * @opcodes: the codes
 * @file_info: the raw data
 * Return: SUCCESS if there is an opcode
 */
int analyze_op(char **file_info_lines, instruction_t *opcodes, char *file_info)
{

	char **arguments = NULL;
	int opcode_executed = FAILURE;
	int is_opcode = SUCCESS;
	unsigned int i = 0;

	while (file_info_lines[i])
	{
		arguments = get_arguments(file_info_lines[i]);
		opcode_executed = validate_opcode(arguments, opcodes, i + 1,
						  file_info_lines, file_info);
		if (opcode_executed == FAILURE)
		{
			print_error(OPCODE, arguments[0], i + 1);
			free(file_info_lines);
			free(file_info);
			free(arguments);
			free_stack();
			is_opcode = FAILURE;
			return (is_opcode);
		}
		free(arguments);
		i++;
	}
	free(file_info_lines);
	free(file_info);
	return (is_opcode);
}
/**
 * validate_opcode - analize opcode to execute it
 * @arguments: the codes
 * @opcodes: the codes
 * @lines: number of lines
 * @file_info_lines:the data in lines
 * @file_info: raw data
 * Return: SUCCESS if there is an opcode
 */
int validate_opcode(char **arguments, instruction_t *opcodes,
		    unsigned int lines, char **file_info_lines, char *file_info)
{
	stack_t *new_stack_t = NULL;
	int i = 0;
	int is_integer = 0;
	int opcode_executed = FAILURE;
	unsigned int line = 1;

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(arguments[0], opcodes[i].opcode) == SUCCESS)
		{
			is_integer = check_int(arguments[1]);
			if (strcmp(arguments[0], "push") == SUCCESS && is_integer == SUCCESS)
			{
				new_stack_t = malloc(sizeof(*new_stack_t));
				if (new_stack_t == NULL)
				{
					print_error(MALLOC, NULL, 0);
					exit(EXIT_FAILURE);
				}
				new_stack_t->prev = NULL;
				new_stack_t->next = NULL;
				new_stack_t->n = atoi(arguments[1]);
			}
			else if (strcmp(arguments[0], "push") == SUCCESS && is_integer == FAILURE)
			{
				free(new_stack_t);
				free_stack();
				print_error(PUSH, NULL, lines);
				free(file_info_lines);
				free(file_info);
				free(arguments);
				exit(EXIT_FAILURE);
			}
			/* execute opcode */
			opcodes[i].f(&new_stack_t, line);
			opcode_executed = SUCCESS;
			line++;
		}
	}
	return (opcode_executed);
}
/**
 * get_arguments - get arguments from file of opcodes
 * @string: the file string
 * Return: arguments
 */
char **get_arguments(char *string)
{
	char **arguments = NULL;
	char *token = NULL;
	int i = 0;

	arguments = malloc((MAX_OPCODE_ARGS + 1) * sizeof(token));
	if (arguments == NULL)
	{
		print_error(MALLOC, NULL, 0);
		exit(EXIT_FAILURE);
	}
	token = strtok(string, " ");
	while (i < MAX_OPCODE_ARGS)
	{
		arguments[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	arguments[MAX_OPCODE_ARGS] = NULL;
	return (arguments);
}
