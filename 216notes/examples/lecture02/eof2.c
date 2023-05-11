#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* illustrates another way of reading until the end of the input; also just
 * counts the number of integers that are read
 *
 * run this example the same ways as the eof.c example
 */

int main(void) {
  int n, count= 0;

  while (scanf("%d", &n) != EOF)  /* read a number and check for eof */
    count++;

  printf("%d integers were read.\n", count);

  return 0;
}
