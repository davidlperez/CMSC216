#include <stdio.h>
#include <assert.h>
#include "elephant.h"
#include "check-elephant.h"

/* CMSC 216, Spring 2023, Project #6
 * Public test 3 (public03.c)
 *
 * Tests creating several elephants to ensure that their data does not
 * conflict.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Elephant *elephant1= new_elephant("Ellie", ASIAN, 11144, 9742, 6.5f);
  Elephant *elephant2= new_elephant("Elton", AFRICAN, 64321, 10243, 7.5f);
  Elephant *elephant3= new_elephant("Ellis", AFRICAN, 88444, 8455, 8.5f);

  /* check the first elephant's data, now calling get_name() and
     get_type() */
  assert(elephant1 != NULL);
  assert(check_elephant(elephant1, "Ellie", ASIAN, 11144, 9742, 6.5f) == 1);

  /* check the second elephant's data */
  assert(elephant2 != NULL);
  assert(check_elephant(elephant2, "Elton", AFRICAN, 64321, 10243,
                        7.5f) == 1);

  /* check the third elephant's data */
  assert(elephant3 != NULL);
  assert(check_elephant(elephant3, "Ellis", AFRICAN, 88444, 8455,
                        8.5f) == 1);

  printf("All assertions passed!\n");

  return 0;
}
