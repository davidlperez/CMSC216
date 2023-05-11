#include <stdio.h>
#include <assert.h>
#include "elephant.h"
#include "check-elephant.h"

/* CMSC 216, Spring 2023, Project #5
 * Public test 4 (public04.c)
 *
 * Tests calling compare() and print_elephant().
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Elephant *elephant1= new_elephant("Erma", ASIAN, 16374, 6548, 6.35f),
           *elephant2= new_elephant("Erma", ASIAN, 16374, 6548, 6.35f);

  assert(compare(elephant1, elephant2) == 1);

  /* now change one field at a time and ensure that compare() returns 0 */

  elephant2->elephant_type= AFRICAN;  /* change type */
  assert(compare(elephant1, elephant2) == 0);
  elephant2->elephant_type= ASIAN;  /* and reset type */

  elephant2->id= 99999;  /* change id */
  assert(compare(elephant1, elephant2) == 0);
  elephant2->id= 16374;  /* and reset id */

  elephant2->weight= 9876;  /* change weight */
  assert(compare(elephant1, elephant2) == 0);
  elephant2->weight= 6548;  /* and reset weight */

  elephant2->trunk_length= 10.5f;  /* change trunk_length */
  assert(compare(elephant1, elephant2) == 0);
  elephant2->trunk_length= 6.35f;  /* and reset trunk_length */

  change_name(elephant2, "Elmer");  /* change name */
  assert(compare(elephant1, elephant2) == 0);
  change_name(elephant2, "Erma");  /* and reset name */

  /* test printing */
  print_elephant(elephant1);
  print_elephant(elephant2);

  /* the elephants should be equal again */
  assert(compare(elephant1, elephant2) == 1);

  /* just a final check that the elephants' data is right */
  assert(check_elephant(elephant1, "Erma", ASIAN, 16374, 6548, 6.35f) == 1);
  assert(check_elephant(elephant2, "Erma", ASIAN, 16374, 6548, 6.35f) == 1);

  printf("All assertions passed!\n");

  return 0;
}
