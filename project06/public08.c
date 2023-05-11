#include <stdio.h>
#include <assert.h>
#include "elephant.h"
#include "check-elephant.h"

/* CMSC 216, Spring 2023, Project #6
 * Public test 8 (public08.c)
 *
 * Tests passing NULL into the functions' Elephant pointer parameters (which
 * should have no effect, but not crash).
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Elephant *elephant= new_elephant("Elvira", AFRICAN, 28673, 7821, 9.3f);
  unsigned short result;
  enum type elephant_type;

  /* none of these calls should change anything */
  result= get_type(NULL, &elephant_type);
  assert(result == 0);

  result= get_type(NULL, NULL);
  assert(result == 0);

  assert(get_name(NULL) == NULL);

  print_elephant(NULL);  /* should not generate any output */

  assert(compare(NULL, elephant) == -1);
  assert(compare(elephant, NULL) == -1);
  assert(compare(NULL, NULL) == -1);

  assert(copy(NULL, NULL) == 0);

  assert(change_name(NULL, "Elise") == 0);
  assert(change_name(elephant, NULL) == 0);

  /* verify that the elephant's data was unaffected by any of the calls
     above */
  assert(elephant != NULL);
  assert(check_elephant(elephant, "Elvira", AFRICAN, 28673, 7821, 9.3f) == 1);

  printf("All assertions passed!\n");

  return 0;
}
