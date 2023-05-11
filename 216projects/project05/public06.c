#include <stdio.h>
#include <assert.h>
#include "elephant.h"

/* CMSC 216, Spring 2023, Project #5
 * Public test 6 (public06.c)
 *
 * Tests calling copy().
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Elephant elvis= new_elephant(AFRICAN, 37045, 8523, 9.53f),
           ellsworth= new_elephant(ASIAN, 12345, 7000, 7.55f);

  assert(copy(&ellsworth, &elvis) == 1);

  print_elephant(ellsworth);

  assert(get_type(elvis) == get_type(ellsworth));
  assert(get_id(elvis) == get_id(ellsworth));
  assert(get_weight(elvis) == get_weight(ellsworth));
  assert(get_trunk_length(elvis) == get_trunk_length(ellsworth));

  printf("Perfect!\n");

  return 0;
}
