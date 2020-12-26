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
        monty_data.opcodes_list[3].opcode = "pop";
        monty_data.opcodes_list[3].f = pop;
        monty_data.opcodes_list[4].opcode = "swap";
        monty_data.opcodes_list[4].f = swap;
        monty_data.opcodes_list[5].opcode = "add";
        monty_data.opcodes_list[5].f = add;
        monty_data.opcodes_list[6].opcode = "nop";
        monty_data.opcodes_list[6].f = NULL;
        monty_data.opcodes_list[7].opcode = "sub";
        monty_data.opcodes_list[7].f = sub;
        monty_data.opcodes_list[8].opcode = "div";
        monty_data.opcodes_list[8].f = divi;

        monty_data.opcodes_list[9].opcode = NULL;
        monty_data.opcodes_list[9].f = NULL;
}