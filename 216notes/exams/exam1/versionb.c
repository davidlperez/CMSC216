#include <stdio.h>
#include <assert.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Program where you need to type your function for the bitwise operator
 * coding exam question (#4) to verify that something that you lost credit
 * for was actually correct if you think that a mistake was made in grading,
 * *before* asking for the grading to be reconsidered.
 */

static short num_pairs(unsigned int n);
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
short num_pairs(unsigned int n) {
  return 216;  /* just to make the code compile as originally provided */
}

int main(void) {
  /* test num_pairs() on numbers that have all identical pairs of bits */
  assert(num_pairs(0xffffffffu) == 31);
  assert(num_pairs(0x00000000u) == 31);
  /* test num_pairs() on numbers that have only one nonidentical pair of
     bits */
  assert(num_pairs(0x7fffffffu) == 30);
  assert(num_pairs(0xfffffffeu) == 30);
  /* test num_pairs() on numbers that have two nonidentical pairs of bits */
  assert(num_pairs(0xfff7ffffu) == 29);
  assert(num_pairs(~0xfff3ffffu)== 29);
  assert(num_pairs(0xffffefffu) == 29);
  /* test num_pairs() on numbers that have several identical pairs of
     bits */
  assert(num_pairs(0x557c3555u) == 8);
  assert(num_pairs(0x557c1555u) == 8);
  /* test num_pairs() on numbers that have just three identical pairs of
     bits */
  assert(num_pairs(0xaaaaaaa3u) == 3);
  /* test num_pairs() on numbers that have just two identical pairs of
     bits */
  assert(num_pairs(0xaacaaaaau) == 2);
  assert(num_pairs(0xaa8aaaaau) == 2);
  assert(num_pairs(0xaaaaaaacu) == 2);
  /* test num_pairs() on numbers that have just one identical pair of
     bits */
  assert(num_pairs(0xaaaaaaabu) == 1);
  assert(num_pairs(0x2aaaaaaau) == 1);
  assert(num_pairs(0x55555554u) == 1);
  assert(num_pairs(0xb5555555u) == 1);
  /* test num_pairs() on numbers that don't have any identical pairs of
     bits */
  assert(num_pairs(0xaaaaaaaau) == 0);
  assert(num_pairs(0x55555555u) == 0);

  printf("Success!\n");

  return 0;
}
