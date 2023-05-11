#include <stdio.h>
#include <assert.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Program where you need to type your function for the bitwise operator
 * coding exam question (#4) to verify that something that you lost credit
 * for was actually correct if you think that a mistake was made in grading,
 * *before* asking for the grading to be reconsidered.
 */

static unsigned short leftmost_same_bit(unsigned int n, unsigned int m);
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
unsigned short leftmost_same_bit(unsigned int n, unsigned int m) {
  return 216;  /* just to make the code compile as originally provided */
}

int main(void) {
  /* test leftmost_same_bit() on numbers that have no bits the same */
  assert(leftmost_same_bit(0xffffffffu, 0x00000000) == 0);
  assert(leftmost_same_bit(0xaaaaaaaau, 0x55555555) == 0);
  /* test leftmost_same_bit() on numbers whose leftmost bits are the same */
  assert(leftmost_same_bit(0xffffffffu, 0x8fffffff) == 32);
  assert(leftmost_same_bit(0x80000000u, 0xffffffff) == 32);
  /* test leftmost_same_bit() on numbers where some internal bits are the
     same */
  assert(leftmost_same_bit(0x00a00000u, 0xff300000) == 23);
  assert(leftmost_same_bit(0x0000a075u, 0xffff2053) == 15);
  assert(leftmost_same_bit(0xfffffffeu, 0x00000003) == 2);
  /* test leftmost_same_bit() on numbers whose rightmost bits are the
     same */
  assert(leftmost_same_bit(0xffffffffu, 0x00000001) == 1);

  printf("Success!\n");

  return 0;
}
