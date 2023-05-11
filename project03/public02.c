#include <stdio.h>
#include "raisin.h"

/* CMSC 216, Spring 2023, Project #3
 * Public test 2 (public02.c)
 *
 * Tests calling print_instruction() on some other types of instructions.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define NUM_INSTRUCTIONS 5

int main(void) {
  unsigned int instructions[NUM_INSTRUCTIONS]= {0x4bc00000, 0x53400000,
                                                0xa80027e8, 0x08000000,
                                                0x00000000};
  int i;

  for (i= 0; i < NUM_INSTRUCTIONS; i++)
    print_instruction(instructions[i]);

  return 0;
}
