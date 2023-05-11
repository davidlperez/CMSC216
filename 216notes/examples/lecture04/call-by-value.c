#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Demonstrates that parameters are passed by value in C.  n in main() is
 * passed into the parameter x of abs_value().  The function modifies x.
 * What is the value of the argument n that's passed into x when the
 * function returns, and why?
 */

static int abs_value(int x);

static int abs_value(int x) {
  if (x < 0)
    x= -x;

  return x;
}

int main(void) {
  int n= -10, a;

  a= abs_value(n);
  printf("%d %d\n", a, n);

  return 0;
}
