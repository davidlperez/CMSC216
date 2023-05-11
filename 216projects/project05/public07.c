#include <stdio.h>
#include <assert.h>
#include "elephant.h"

/* CMSC 216, Spring 2023, Project #5
 * Public test 7 (public07.c)
 *
 * Tests calling change_id() with a NULL pointer argument.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Elephant elmer= new_elephant(AFRICAN, 28475, 9809, 8.34f);

  change_id(NULL, 28575);

  assert(get_type(elmer) == AFRICAN);
  assert(get_id(elmer) == 28475);
  assert(get_weight(elmer) == 9809);
  assert(get_trunk_length(elmer) == 8.34f);

  printf("Perfect!\n");

  return 0;
}
