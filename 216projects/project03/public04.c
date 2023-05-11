#include <stdio.h>
#include <assert.h>
#include "raisin.h"

/* CMSC 216, Spring 2023, Project #3
 * Public test 4 (public04.c)
 *
 * Tests calling print_instruction() on an invalid instruction.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  /* this instruction is valid */
  assert(print_instruction(0x0a960000) == 1);

  /* but this one is invalid so it should not print anything */
  assert(print_instruction(0xffffffff) == 0);

  printf("The assertions were all extremely successful!\n");

  return 0;
}
