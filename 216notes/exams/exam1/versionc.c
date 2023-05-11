#include <stdio.h>
#include <assert.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Program where you need to type your function for the bitwise operator
 * coding exam question (#4) to verify that something that you lost credit
 * for was actually correct if you think that a mistake was made in grading,
 * *before* asking for the grading to be reconsidered.
 */

static unsigned int fill_on_left(unsigned int n);
void print_binary(unsigned int n);

/* just for your use in debugging */
void print_binary(unsigned int n) {
  int i, tmp= sizeof(n) * 8;

  printf("0x%08x in binary is ", n);
  for (i= 0; i < tmp; i++) {
    if ((n & (1 << ((tmp - i) - 1))) != 0)
      printf("1");
    else printf("0");

    /* print a blank space every 4 bits to make reading the numbers easier */
    if ((i + 1) % 4 == 0 && i > 0)
      printf(" ");
  }

  printf("\n");
}

/* remove the return statement below, then type your function in here */
unsigned int fill_on_left(unsigned int n) {
  return 216;  /* just to make the code compile as originally provided */
}

int main(void) {
  /* test fill_on_left() on numbers whose leftmost bit is 1 */
  assert(fill_on_left(0xffffffffu) == 0xffffffffu);
  assert(fill_on_left(0x80000000u) == 0x80000000u);
  /* test fill_on_left() on numbers whose leftmost 1 bit is some internal
     bit */
  assert(fill_on_left(0x00000040u) == 0xffffffc0u);
  assert(fill_on_left(0x00007654u) == 0xfffff654u);
  /* test fill_on_left() on a number whose rightmost bit is 1 (just the
     number 1) */
  assert(fill_on_left(0x00000001u) == 0xffffffffu);
  /* test fill_on_left() on a number that has no 1 bits (just the number 0) */
  assert(fill_on_left(0x00000000u) == 0x00000000u);

  printf("Success!\n");

  return 0;
}
