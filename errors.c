#include "monty.h"

/**
 * print_error - prints error messages from monty
 * @error_number: code of error
 * @string: representation of the file name or anoother utility
 * @num: representation of the line of error or another utility
 */
void print_error(int error_number, char *string, int num)
{
	switch (error_number)
	{
	case USAGE:
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
		break;
	case OPEN_FILE:
		fprintf(stderr, "Error: Can't open file %s\n", string);
		break;
	case MALLOC:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case READ:
		fprintf(stderr, "Error: Can't read file %s\n", string);
		break;
	case OPCODE:
		fprintf(stderr, "L%d: unknown instruction %s\n", num, string);
		break;
	case PUSH:
		fprintf(stderr, "L%d: usage : push integer\n", num);
		break;
	case PINT:
		fprintf(stderr, "L%d: can't pint, stack empty\n", num);
		break;
	case POP:
		fprintf(stderr, "L%d: can't pop an empty stack\n", num);
		break;
	case SWAP:
		fprintf(stderr, "L%d: can't swap, stack too short\n", num);
		break;
	case ADD:
		fprintf(stderr, "L%d: can't add, stack too short\n", num);
		break;
	default:
		break;
	}
	free_stack();
}
