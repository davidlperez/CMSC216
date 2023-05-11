#include <stdio.h>
#include <assert.h>
#include "elephant.h"

/* CMSC 216, Spring 2023, Project #5
 * Public test 10 (public10.c)
 *
 * Tests the return value of init_elephant(), change_id(), and copy() when
 * their parameters are NULL.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Elephant ellis= new_elephant(ASIAN, 83811, 9244, 8.83f),
           elsa= new_elephant(AFRICAN, 98334, 8239, 7.03f);

  assert(init_elephant(NULL, ASIAN, 11111, 1111, 9.99f) == 0);
  assert(change_id(NULL, 11111) == 0);
  assert(copy(NULL, NULL) == 0);

  assert(get_type(ellis) == ASIAN);
  assert(get_id(ellis) == 83811);
  assert(get_weight(ellis) == 9244);
  assert(get_trunk_length(ellis) == 8.83f);

  assert(get_type(elsa) == AFRICAN);
  assert(get_id(elsa) == 98334);
  assert(get_weight(elsa) == 8239);
  assert(get_trunk_length(elsa) == 7.03f);

  printf("Perfect!\n");

  return 0;
}
