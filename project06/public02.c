#include <stdio.h>
#include <assert.h>
#include "elephant.h"
#include "check-elephant.h"

/* CMSC 216, Spring 2023, Project #6
 * Public test 2 (public02.c)
 *
 * Tests get_type().
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Elephant *elephant= new_elephant("Ellie", ASIAN, 11144, 9742, 6.5f);
  enum type elephant_type;

  assert(get_type(elephant, &elephant_type) == 1);
  assert(elephant_type == ASIAN);

  /* also check all the elephant's data using our check_elephant()
     function */
  assert(check_elephant(elephant, "Ellie", ASIAN, 11144, 9742, 6.5f) == 1);

  printf("All assertions passed!\n");

  return 0;
}
