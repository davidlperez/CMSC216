#include <stdio.h>
#include "raisin.h"

/* CMSC 216, Spring 2023, Project #3
 * Public test 3 (public03.c)
 *
 * Tests calling print_instruction() on even some other types of
 * instructions.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define NUM_INSTRUCTIONS 3

int main(void) {
  unsigned int instructions[NUM_INSTRUCTIONS]= {0xa3803810, 0x93c02f10,
                                                0x9ac03910};
  int i;

  for (i= 0; i < NUM_INSTRUCTIONS; i++)
    print_instruction(instructions[i]);

  return 0;
}
