#include <stdio.h>
#include <assert.h>
#include "elephant.h"

/* CMSC 216, Spring 2023, Project #5
 * Public test 9 (public09.c)
 *
 * Tests calling copy() with NULL pointer arguments.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Elephant elaine= new_elephant(AFRICAN, 17262, 10020, 9.32f),
           elijah= new_elephant(ASIAN, 19273, 7223, 6.29f);

  copy(NULL, NULL);

  assert(get_type(elaine) == AFRICAN);
  assert(get_id(elaine) == 17262);
  assert(get_weight(elaine) == 10020);
  assert(get_trunk_length(elaine) == 9.32f);

  assert(get_type(elijah) == ASIAN);
  assert(get_id(elijah) == 19273);
  assert(get_weight(elijah) == 7223);
  assert(get_trunk_length(elijah) == 6.29f);

  printf("Perfect!\n");

  return 0;
}
