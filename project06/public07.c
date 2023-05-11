#include <stdio.h>
#include <assert.h>
#include "elephant.h"
#include "check-elephant.h"

/* CMSC 216, Spring 2023, Project #6
 * Public test 7 (public07.c)
 *
 * Tests passing NULL into the name parameters of the functions that have a
 * name parameter.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Elephant *elephant1, *elephant2;

  elephant1= new_elephant("Ellis", AFRICAN, 11144, 9742, 6.5f);
  elephant2= elephant1;  /* set elephant2 to a non-NULL value */

  /* after the following call, elephant2 should be NULL */
  elephant2= new_elephant(NULL, AFRICAN, 64321, 10243, 7.5f);
  assert(elephant2 == NULL);

  /* this should return 0 without changing anything, and by the way not
     crash */
  change_name(elephant1, NULL);

  /* check elephant1's data */
  assert(elephant1 != NULL);
  /* the elephant's name should be unchanged by calling change_name() with
     NULL above */
  assert(check_elephant(elephant1, "Ellis", AFRICAN, 11144, 9742, 6.5f)
         == 1);

  printf("All assertions passed!\n");

  return 0;
}
