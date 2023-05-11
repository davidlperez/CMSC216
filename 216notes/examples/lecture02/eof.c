#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Illustrates reading until the end of the input; just counts the number of
 * integers that are read.
 *
 * Run this example in two ways:
 * - First by typing any numbers (interactive input), pressing control-d when
 *   you want the input to end.
 * - Second using input redirection, as eof.x < numbers (assuming that eof.x
 *   is the name of the compiled program, and note that numbers is a data file
 *   file also in this directory).
 *
 * After running it and seeing how it works, it may seem that it would be
 * easier to write the program with only one scanf(), where the loop would
 * just look like this:
 *
 * while (!feof(stdin)) {
 *   scanf("%d", &n);
 *   count++;
 * }
 *
 * This almost works, but not quite.  Why not?  Try copying this example to a
 * C program with another name (like my-eof.c), editing it to change it this
 * way, and running it in different cases to see why this doesn't quite work
 * right.
 */

int main(void) {
  int n, count= 0;

  scanf("%d", &n);  /* read a number */
  while (!feof(stdin)) {
    count++;
    scanf("%d", &n);  /* read a number */
  }

  printf("%d integers were read.\n", count);

  return 0;
}
