#include <stdio.h>
#include <assert.h>
#include "raisin.h"

/* CMSC 216, Spring 2023, Project #3
 * Public test 8 (public08.c)
 *
 * Tests calling disassemble() on a program that has valid instructions and
 * starts at the beginning of memory.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define PROGRAM_SIZE 15
#define START_ADDR 0
#define DATA_SEGMENT_SIZE 0

int main(void) {
  unsigned int memory[NUM_WORDS]= {0};
  unsigned int program[PROGRAM_SIZE]= {0x12960000, 0x239c0000, 0x32d80000,
                                       0x43d40000, 0x5b580000, 0x7b1c0000,
                                       0x82de0000, 0x4bc00000, 0x53400000,
                                       0xa80027e8, 0x08000000, 0xa3803810,
                                       0x93c02f10, 0x9ac03910, 0x8b560000};

  /* load the program into memory starting at address 0, it has 15 total
     words, and its data segment is 0 words large */
  assert(load_program(memory, program, START_ADDR, PROGRAM_SIZE,
                      DATA_SEGMENT_SIZE) == 1);

  /* now disassemble */
  assert(disassemble(memory, START_ADDR, PROGRAM_SIZE,
                     DATA_SEGMENT_SIZE) == 1);

  printf("The assertions were all extremely successful!\n");

  return 0;
}
