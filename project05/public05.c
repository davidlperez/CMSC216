#include <stdio.h>
#include <assert.h>
#include "elephant.h"

/* CMSC 216, Spring 2023, Project #5
 * Public test 5 (public05.c)
 *
 * Tests calling compare().
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Elephant elmore1= new_elephant(ASIAN, 83745, 7234, 7.25f),
           elmore2= new_elephant(ASIAN, 83745, 7234, 7.25f),
           elroy= new_elephant(ASIAN, 37458, 7234, 7.25f);

  assert(compare(elmore1, elmore2) == 1);
  assert(compare(elmore1, elroy) == 0);

  printf("Perfect!\n");

  return 0;
}
