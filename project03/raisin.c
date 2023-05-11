/* David Perez
 * dperez7
 * 117915402
 * CMSC216 (0107) Project 3 raisin.c */
#include <stdio.h>
#include "raisin.h"

/* This function takes in an unsigned int as a parameter
 * and extracts the opcode, two register operands, and memory
 * address or constant value from it using bitwise operators.
 * This function then prints out the instructions based on */
unsigned short print_instruction(unsigned int instruction) {
    /* Extract opcode field */
    unsigned int opcode = instruction >> 27;
    /* Extract register1 field */
    unsigned int register1 = (instruction >> 22) & 0x1f;
    /* Extract register2 field */
    unsigned int register2 = (instruction >> 17) & 0x1f;
    /* Extract memory/immediate field */
    unsigned int memory_or_immediate = instruction & 0x1ffff;

    /* Check if opcode is valid */ 
    if (opcode > 21) {
        return 0;
    }

    /* Check if register1 is valid */
    if (register1 > R17) {
        return 0;
    }

    /* Check if register1 is R16 or R17 and opcode modifies its value */
    if ((register1 == R16 || register1 == R17) && 
    (opcode < 11 || opcode > 17)) {
        return 0;
    }

    /* Check if register2 is valid */
    if (register2 > R17) {
        return 0;
    }

    /* Check if memory address is valid */
    if (opcode == LW || opcode == SW || opcode == BRANCH) {
        if (memory_or_immediate % 4 != 0) {
            return 0;
        }
    }

    /* Print opcode and register operands where necessary
     * Prints only the operands actually used by the instruction.
     * i.e. an instruction using only register1 will only print register1
     * and the same for register2, where instructions that use both will
     * print both, and the same for instructions that use neither. */
    switch (opcode) {
        case HALT:
            printf("halt");
            break;
        case SYSCALL:
            printf("syscall");
            break;
        case ADD:
            printf("add");
            printf(" R%d R%d", register1, register2);
            break;
        case SUB:
            printf("sub");
            printf(" R%d R%d", register1, register2);
            break;
        case MUL:
            printf("mul");
            printf(" R%d R%d", register1, register2);
            break;
        case QUOT:
            printf("quot");
            printf(" R%d R%d", register1, register2);
            break;
        case MOD:
            printf("mod");
            printf(" R%d R%d", register1, register2);
            break;
        case AND:
            printf("and");
            printf(" R%d R%d", register1, register2);
            break;
        case OR:
            printf("or");
            printf(" R%d R%d", register1, register2);
            break;
        case NEG:
            printf("neg");
            printf(" R%d", register1);
            break;
        case NOT:
            printf("not");
            printf(" R%d", register1);
            break;
        case EQL:
            printf("eql");
            printf(" R%d R%d", register1, register2);
            break;
        case NEQ:
            printf("neq");
            printf(" R%d R%d", register1, register2);
            break;
        case LT:
            printf("lt");
            printf(" R%d R%d", register1, register2);
            break;
        case LE:
            printf("le");
            printf(" R%d R%d", register1, register2);
            break;
        case GT:
            printf("gt");
            printf(" R%d R%d", register1, register2);
            break;
        case GE:
            printf("ge");
            printf(" R%d R%d", register1, register2);
            break;
        case MOVE:
            printf("move");
            printf(" R%d R%d", register1, register2);
            break;
        case LW:
            printf("lw");
            printf(" R%d", register1);
            break;
        case SW:
            printf("sw");
            printf(" R%d", register1);
            break;
        case LI:
            printf("li");
            printf(" R%d", register1);
            break;
        case BRANCH:
            printf("branch");
            break;
    }

    /* Print memory/immediate operand with a different number 
     * of leading zeros space depending on the opcode;
     * all should take up 5 whitespaces except for LI */
    if (opcode == LI) {
        printf(" %d", memory_or_immediate);
    } else if (opcode == LW || opcode == SW || opcode == BRANCH) {
        printf(" %05d", memory_or_immediate);
    }
   
    /* Print newline */
    printf("\n");

    return 1;
}

/* This function, load_program, simulates the operating system loading a machine
 * into the MAD Raisin's memory, which is represented by the array memory.
 * There are several checks to ensure the start address, program size, and 
 * program array are valid before copying the program array into the memory. */
int load_program(unsigned int memory[], const unsigned int program[], 
    unsigned int start_addr, unsigned short pgm_size,
    unsigned short data_segment_size) {
    /* counter for source array to be copied from */
    unsigned int src_addr = 0;
    /* counter for destination array to be copied into */
    unsigned int dst_addr = start_addr / BYTES_PER_WORD;
    /* for loop counter */
    unsigned short i;
   
    /* Check if start_addr is valid by checking it is evenly divisible by 4 
     * and within the range of valid word addresses */
    if (start_addr % 4 != 0 || start_addr >= NUM_WORDS * BYTES_PER_WORD) {
        return 0;
    }
    
    /* Check if pgm_size is valid by checking that it is not 0 and it does not
     * exceed the number of available word addresses after start_addr */
    if (pgm_size == 0 || pgm_size > NUM_WORDS - start_addr / BYTES_PER_WORD) {
        return 0;
    }
    
    /* Check if there is at least one instruction in the text segment by
     * checking that pgm_size is greater than data_segment_size*/
    if (pgm_size <= data_segment_size / BYTES_PER_WORD) {
        return 0;
    }
    
    /* Copies the program array into memory array */
    for (i = 0; i < pgm_size; i++) {
        memory[dst_addr + i] = program[src_addr + i];
    }
    
    return 1;

}

/* This function, disassemble, iterates through the memory and prints
 * instructions using the print_instruction() function until
 * data_segment_size is left. Then, it prints the remainder as data in 
 * the form of a hexadecimal number (without the 0x preceding). */
unsigned short disassemble(const unsigned int memory[], unsigned int start_addr,
    unsigned int pgm_size, unsigned int data_segment_size) {
    /* for loop counter */
    unsigned int i;
    
    /* Check for invalid parameters by ensuring the start_addr is divisible 
     * by 4, since each word is 4 bytes. It also checks that the program size 
     * is less than the number max number of words, and ensures the remainder 
     * of the parameters are in the correct range, or else it returns 0. */
    if (start_addr % BYTES_PER_WORD != 0 ||
        pgm_size > NUM_WORDS ||
        start_addr / BYTES_PER_WORD + pgm_size > NUM_WORDS ||
        start_addr > NUM_WORDS || data_segment_size == pgm_size) {
        return 0;
    }

    /* Disassemble instructions that calls the print_instruction() function
     * which checks if the instruction is valid and prints it in the correct
     * format if it is. It returns 0 if invalid. */
    for (i = start_addr / BYTES_PER_WORD;
         i < (pgm_size - data_segment_size + start_addr / BYTES_PER_WORD);
         i++) {
        if (print_instruction(memory[i]) == 0) {
            return 0;
        }
    }

    /* Prints data segment for the amount of data_segment_size in the form of 
     * a hexadecimal number. */
    for (i = pgm_size - data_segment_size + start_addr / BYTES_PER_WORD;
         i < pgm_size; i++) {
        printf("%08x\n", memory[i]);
    }

    return 1;
}