#include "monty.h"
/**
 * init_opcodes - initialize upcodes
 */
void init_opcodes(void)
{
        monty_data.opcodes_list[0].opcode = "push";
        monty_data.opcodes_list[0].f = push;
        monty_data.opcodes_list[1].opcode = "pall";
        monty_data.opcodes_list[1].f = pall;
        monty_data.opcodes_list[2].opcode = "pint";
        monty_data.opcodes_list[2].f = pint;
        monty_data.opcodes_list[2].opcode = "pop";
        monty_data.opcodes_list[2].f = pop;

        monty_data.opcodes_list[3].opcode = NULL;
        monty_data.opcodes_list[3].f = NULL;
}