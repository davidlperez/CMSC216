#include <stdio.h>
#include <assert.h>
#include "elephant.h"
#include "check-elephant.h"

/* CMSC 216, Spring 2023, Project #6
 * Public test 10 (public10.c)
 *
 * Ensures that pointer aliasing is not occurring in copy().
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Elephant *elephant1= new_elephant("Elliott", ASIAN, 16491, 7273, 8.25f),
           *elephant2= new_elephant("Elise", AFRICAN, 71632, 9454, 7.75f);

  /* make elephant1's data a copy of elephant2's */
  copy(elephant1, elephant2);

  /* elephant1's name should be independent of elephant2's, so reach in and
     change elephant2's name, which should not affect elephant1's name */
  elephant2->name[4]= 'a';  /* now "Elisa" */

  /* check elephant1's data */
  assert(elephant1 != NULL);
  assert(check_elephant(elephant1, "Elise", AFRICAN, 71632, 9454,
                        7.75f) == 1);

  /* check elephant2's data */
  assert(elephant2 != NULL);
  assert(check_elephant(elephant2, "Elisa", AFRICAN, 71632, 9454,
                        7.75f) == 1);

  printf("All assertions passed!\n");

  return 0;
}
