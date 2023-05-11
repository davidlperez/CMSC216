#include <stdio.h>
#include <assert.h>
#include "elephant.h"
#include "check-elephant.h"
#include "memory-functions.h"

/* CMSC 216, Spring 2023, Project #6
 * Public test 6 (public06.c)
 *
 * Tests copy(), and ensures that it is properly freeing memory and that the
 * heap is correct.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Elephant *elephant1, *elephant2;
  int memory_used;

  /* enable heap checking; to work this must be called before any memory is
     allocated */
  setup_memory_checking();

  elephant1= new_elephant("Elena", ASIAN, 16491, 9273, 7.25f);
  elephant2= new_elephant("Elliott", AFRICAN, 71632, 9454, 7.75f);

  memory_used= get_memory_in_use();  /* get free memory amount */

  copy(elephant1, elephant2);

  /* check that elephant1's data is now the same as elephant2's */
  assert(elephant1 != NULL);
  assert(check_elephant(elephant1, "Elliott", AFRICAN, 71632, 9454,
                        7.75f) == 1);

  /* set elephant1's name back to its original value */
  change_name(elephant1, "Elena");

  /* ensure that the amount of memory in use is the same as when
     get_memory_in_use() was called above */
  assert(get_memory_in_use() == memory_used);

  /* just a final check that the elephants' data is right */
  assert(check_elephant(elephant1, "Elena", AFRICAN, 71632, 9454,
                        7.75f) == 1);
  assert(check_elephant(elephant2, "Elliott", AFRICAN, 71632, 9454,
                        7.75f) == 1);

  check_heap();

  printf("All assertions passed!\n");

  return 0;
}
