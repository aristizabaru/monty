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
#define STACK 0
#define QUEUE 1
#define VALID_OPCODES 17
#define ITEMS_TO_FREE 3
#define BUFFER_SIZE 1024
#define SUCCESS 1
#define FAILURE 0
#define SHORT_STACK 0
#define DIV_BY_0 1
#define EMPTY_STACK 0
#define OUT_OF_RANGE 1

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
 * struct global_s - struct for magament data inside the opcode program
 * @head: porinter to first node in the stack linked list
 * @behavior: stack or queue code for functionality
 * @current_line: current line of execution in file
 * @lines_total: total number of lines un file
 * @file_data: the data of the file loaded into the program
 * @data_index: current index in the data. What's been read
 * @file_name: the name of the file loaded into the program
 * @current_opcode: current execution of opcode
 * @current_opcode_int: current execution int of current opcode
 * @opcodes_list: list of valid opcodes and their execution functions
 * @free_memory: list of allocated string to be free
 */
typedef struct global_s
{
	stack_t *head;
	/* ssize_t top; */
	int behavior;
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
void error_pop(void);
void error_swap(void);
void error_add(void);

/* errors3.c */
void error_sub(void);
void error_divi(int code);
void error_mul(void);
void error_mod(int code);
void error_pchar(int code);

/* helper.c */
void get_fileName(char *path);
unsigned int get_lineCount(char *string);
int cmp_code(char *real_opcode, char *opcode);
int check_int(char *str);
void skip_line(void);

/* init_opcodes.c */
void init_opcodes(void);

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

/* opcodes_exe.c */
void free_stack(void);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

/* opcodes_exe2.c */
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divi(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);

/* opcodes_exe3.c */
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

#endif /* __MONTY__H__ */
