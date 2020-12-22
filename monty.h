#ifndef __MONTY__H__
#define __MONTY__H__
/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
/* MACROS */
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define SUCCESS 0
#define FAILURE -1
#define USAGE 2
#define OPEN_FILE 3
#define MALLOC 4
#define READ 5
#define OPCODE 6
#define PUSH 7
#define PINT 8
#define BUFFER_SIZE 1024
#define MAX_OPCODE_ARGS 2
/* STRUCTURES */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* GLOBAL VARIABLES */
extern stack_t *head;

/* PROTOTYPES */
void print_error(int error_number, char *string, int num);
char *get_fileName(char *path);
int open_file(char *path, char *file_name);
char *read_file(int fd_monty, char *file_name);
char *init_buffer(int buff_size);
char *buffer_to_fileinfo(char *buffer, char *file_info, int character);
char **get_lines(char *file_info);
int get_lineCount(char *string);
int analyze_op(char **file_info_lines, instruction_t *opcodes,
					char *file_info);
char **get_arguments(char *string);
int validate_opcode(char **arguments, instruction_t *opcodes,
						  unsigned int lines, char **file_info_line, char *file_info);
int _strcmp(char *str1, char *str2);
int check_int(char *str);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(void);
void pint(stack_t **stack, unsigned int line_number);

#endif
