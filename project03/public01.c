#include <stdio.h>
#include "raisin.h"

/* CMSC 216, Spring 2023, Project #3
 * Public test 1 (public01.c)
 *
 * Tests calling print_instruction() on a few types of instructions.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define NUM_INSTRUCTIONS 7

int main(void) {
  unsigned int instructions[NUM_INSTRUCTIONS]= {0x12960000, 0x239c0000,
                                                0x32d80000, 0x43d40000,
                                                0x5b580000, 0x7b1c0000,
                                                0x82de0000};
  int i;

  for (i= 0; i < NUM_INSTRUCTIONS; i++)
    print_instruction(instructions[i]);

  return 0;
}
