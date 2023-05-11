#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* illustrates both arithmetic overflow and underflow */

int main(void) {
  int x= 2000000000, y= -2147483648, z;
  unsigned int u= 0;

  /* x is initialized to a value that, when multiplied by 2, will be larger
     than an int (on the Grace machines) */
  printf("x is %d\n", x);
  /* y is initialized to the smallest negative int (on Grace) */
  printf("y is %d\n", y);
  /* u is obviously the smallest possible unsigned value */
  printf("u is %d\n\n", u);

  z= x * 2;  /* what happens (on Grace) when we multiply x by 2? */
  printf("x * 2 is %d\n", z);

  z= y - 1;  /* what happens (on Grace) when we subtract 1 from y? */
  printf("y - 1 is %d\n", z);

  u--;  /* what happens (on Grace) when we decrement u? */
  printf("u-- is %u\n", u);

  return 0;
}
