#include <stdio.h>
#include <assert.h>
#include "elephant.h"

/* CMSC 216, Spring 2023, Project #5
 * Public test 1 (public01.c)
 *
 * Tests calling new_elephant() and checking that the elephant's data was
 * stored correctly.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Elephant ellie= new_elephant(ASIAN, 12513, 8500, 5.65f);

  assert(get_type(ellie) == ASIAN);
  assert(get_id(ellie) == 12513);
  assert(get_weight(ellie) == 8500);
  assert(get_trunk_length(ellie) == 5.65f);

  printf("Perfect!\n");

  return 0;
}
