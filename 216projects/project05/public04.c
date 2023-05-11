#include <stdio.h>
#include <assert.h>
#include "elephant.h"

/* CMSC 216, Spring 2023, Project #5
 * Public test 4 (public04.c)
 *
 * Tests calling change_id().
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Elephant elise= new_elephant(AFRICAN, 28475, 9809, 8.34f);

  assert(change_id(&elise, 28575) == 1);

  assert(get_type(elise) == AFRICAN);
  assert(get_id(elise) == 28575);
  assert(get_weight(elise) == 9809);
  assert(get_trunk_length(elise) == 8.34f);

  printf("Perfect!\n");

  return 0;
}
