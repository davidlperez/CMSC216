#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Illustrates the purpose of using standard error output (stderr) as
 * opposed to standard output (stdout).  Also uses a random number (from
 * Chapter 16).  Run it normally and look for the one error message mixed
 * in, at a random location, with all the "normal" output; it's not so easy
 * to notice.  Then run it with (standard) output redirected to an output
 * file, e.g., redirecting-output.x > out (of course use whatever output
 * filename you like instead of "out"; it's not what's important).
 */

#define MAX 1000

int main(void) {
  int i, j;

  /* seed the random number generator with the current time */
  srand((unsigned int) time(NULL));

  /* only one output message, out of MAX messages, will be the error
     message */
  j= rand() % MAX;

  for (i= 1; i <= MAX; i++)
    if (i != j) {
      printf("This simulates lots and lots of normal\n");
      printf("output that this program is producing.\n");
    } else {
      fprintf(stderr, "This simulates a small number\n");
      fprintf(stderr, "of error/warning messages.\n");
    }

  return 0;
}
