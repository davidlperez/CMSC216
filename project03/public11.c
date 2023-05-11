#include <stdio.h>
#include <assert.h>
#include "raisin.h"

/* CMSC 216, Spring 2023, Project #3
 * Public test 11 (public11.c)
 *
 * Tests calling disassemble() on a program that contains an invalid
 * instruction, and ensures that it returns 0 without printing anything.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define PROGRAM_SIZE 15
#define START_ADDR 0
#define DATA_SEGMENT_SIZE 0

int main(void) {
  unsigned int memory[NUM_WORDS]= {0xffffffff, 0x239c0000, 0x32d80000,
                                   0x43d40000, 0x5b580000, 0x7b1c0000,
                                   0x82de0000, 0x4bc00000, 0x53400000,
                                   0xa80027e8, 0x08000000, 0xa3803810,
                                   0x93c02f10, 0x9ac03910, 0x8b560000};

  /* note we did not use load_program() to load the program in memory
   * because it would have choked due to the invalid first instruction; we
   * just used the initializer values to put the program words directly in
   * memory */

  /* disassemble, but nothing should be printed */
  assert(disassemble(memory, START_ADDR, PROGRAM_SIZE,
                     DATA_SEGMENT_SIZE) == 0);

  printf("The assertions were all extremely successful!\n");

  return 0;
}
