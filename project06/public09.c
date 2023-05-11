#include <stdio.h>
#include <assert.h>
#include "elephant.h"
#include "check-elephant.h"

/* CMSC 216, Spring 2023, Project #6
 * Public test 9 (public09.c)
 *
 * Ensures that pointer aliasing is not occurring in new_elephant().
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  char name[]= "Elizabeth";
  Elephant *elephant= new_elephant(name, ASIAN, 81643, 8225, 9.2f);

  /* the elephant's name should be independent of the local string variable
     "name", so change the value of "name" to be able to check this */
  name[3]= 's';  /* now "Elisabeth" */

  assert(elephant != NULL);
  /* changing the local string variable "name" should not have affected the
     elephant's name, unless the elephant's name field is incorrectly
     pointing to "name" */
  assert(check_elephant(elephant, "Elizabeth", ASIAN, 81643, 8225,
                        9.2f) == 1);

  printf("All assertions passed!\n");

  return 0;
}
