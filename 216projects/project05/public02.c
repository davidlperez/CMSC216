#include <stdio.h>
#include <assert.h>
#include "elephant.h"

/* CMSC 216, Spring 2023, Project #5
 * Public test 2 (public02.c)
 *
 * Tests calling init_elephant() and checking that the elephant's data was
 * stored correctly.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Elephant elton;

  assert(init_elephant(&elton, AFRICAN, 18546, 9325, 7.35f) == 1);

  assert(get_type(elton) == AFRICAN);
  assert(get_id(elton) == 18546);
  assert(get_weight(elton) == 9325);
  assert(get_trunk_length(elton) == 7.35f);

  printf("Perfect!\n");

  return 0;
}
