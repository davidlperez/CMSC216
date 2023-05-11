#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Illustrates why "void" is necessary in C (not empty parentheses), i.e.,
 * shows what can be done wrong- without being detected- if an incorrect
 * prototype is used.
 */

static int f();  /* this prototype is clearly wrong for f() */

int main(void) {
  int x;

  x= f(1, 3, 5);
  printf("f() returned %d.\n\n", x);

  x= f(7);
  printf("f() returned %d.\n", x);

  return 0;
}

static int f(int a, int b) {
  printf("f()'s parameters are %d and %d.\n", a, b);

  return a + b;
}
