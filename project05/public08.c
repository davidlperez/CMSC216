#include <stdio.h>
#include <assert.h>
#include "elephant.h"

/* CMSC 216, Spring 2023, Project #5
 * Public test 8 (public08.c)
 *
 * Tests calling init_elephant() with a NULL pointer argument.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Elephant elvira= new_elephant(ASIAN, 86489, 8890, 8.83f);

  init_elephant(NULL, AFRICAN, 83274, 8000, 9.50f);

  assert(get_type(elvira) == ASIAN);
  assert(get_id(elvira) == 86489);
  assert(get_weight(elvira) == 8890);
  assert(get_trunk_length(elvira) == 8.83f);

  printf("Perfect!\n");

  return 0;
}
