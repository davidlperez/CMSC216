#include <stdio.h>
#include <assert.h>
#include "elephant.h"

/* CMSC 216, Spring 2023, Project #5
 * Public test 3 (public03.c)
 *
 * Tests creating several elephants to ensure that their data does not
 * conflict.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Elephant elliott= new_elephant(ASIAN, 75842, 10025, 7.50f);
  Elephant elsa= new_elephant(AFRICAN, 83943, 9275, 9.38f);
  Elephant eliana;

  init_elephant(&eliana, ASIAN, 18737, 9740, 8.25f);

  assert(get_type(elliott) == ASIAN);
  assert(get_id(elliott) == 75842);
  assert(get_weight(elliott) == 10025);
  assert(get_trunk_length(elliott) == 7.50f);

  assert(get_type(elsa) == AFRICAN);
  assert(get_id(elsa) == 83943);
  assert(get_weight(elsa) == 9275);
  assert(get_trunk_length(elsa) == 9.38f);

  assert(get_type(eliana) == ASIAN);
  assert(get_id(eliana) == 18737);
  assert(get_weight(eliana) == 9740);
  assert(get_trunk_length(eliana) == 8.25f);

  printf("Perfect!\n");

  return 0;
}
