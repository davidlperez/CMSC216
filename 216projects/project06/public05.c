#include <stdio.h>
#include <assert.h>
#include "elephant.h"
#include "check-elephant.h"
#include "memory-functions.h"

/* CMSC 216, Spring 2023, Project #6
 * Public test 5 (public05.c)
 *
 * Tests calling change_name(), and ensures that it is properly freeing
 * memory and that the heap is correct.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Elephant *elephant;
  int memory_used;

  /* enable heap checking; to work this must be called before any memory is
     allocated */
  setup_memory_checking();

  elephant= new_elephant("Ellie", ASIAN, 11144, 9742, 6.5f);

  memory_used= get_memory_in_use();  /* get free memory amount */

  change_name(elephant, "Elle");
  assert(check_elephant(elephant, "Elle", ASIAN, 11144, 9742, 6.5f) == 1);

  change_name(elephant, "Eleanor");
  assert(check_elephant(elephant, "Eleanor", ASIAN, 11144, 9742,
                        6.5f) == 1);

  change_name(elephant, "Ellie");
  assert(check_elephant(elephant, "Ellie", ASIAN, 11144, 9742, 6.5f) == 1);

  /* ensure that the amount of memory in use is the same as when
     get_memory_in_use() was called above */
  assert(get_memory_in_use() == memory_used);

  check_heap();

  printf("All assertions passed!\n");

  return 0;
}
