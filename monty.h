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
#define VALID_OPCODES 3
#define ITEMS_TO_FREE 3
#define BUFFER_SIZE 1024
#define SUCCESS 1
#define FAILURE 0

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

/**
 * struct global_s - head, top, opcode linenumber, selected opcode, free
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_s
{
	stack_t *head;
	/* ssize_t top; */
	unsigned int current_line;
	unsigned int lines_total;
	char *file_data;
	unsigned int data_index;
	char *file_name;
	char *current_opcode;
	char *current_opcode_int;
	instruction_t opcodes_list[VALID_OPCODES + 1];
	char *free_memory[ITEMS_TO_FREE];
} global_t;

/* GLOBAL VARIABLES */
extern global_t monty_data;

/* PROTOYYPES */
/* errors.c */
void error_usage(void);
void error_malloc(void);
void error_open(void);
void error_read(void);
void error_opcode(void);

/* errors2.c */
void error_push(void);
void error_pint(void);

/* helper.c */
void get_fileName(char *path);
unsigned int get_lineCount(char *string);
void init_opcodes(void);
int cmp_code(char *real_opcode, char *opcode);
int check_int(char *str);

/* helper2.c */
void skip_line(void);

/* memory_handle.c */
void free_all(void);

/* read_handle.c */
unsigned int open_file(char *path);
char *read_file(unsigned int fd_monty);
char *copy_data(char *buffer, char *data, int characters);
char *allocate_memory(int size);

/* execute_monty.c */
void exucute_monty(void);
char *get_opcode(void);
char *copy_opcode(unsigned int firts_idx, unsigned int last_idx);
void execute_opcode(void);
int get_opcode_idx(void);

/* opcodes_exec.c */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(void);

#endif /* __MONTY__H__ */
