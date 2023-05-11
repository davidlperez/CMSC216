#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* illustrates the properties of local variables that have static
   vs. automatic storage */

static void f(void);

static void f(void) {
  static int i= 1;
  int j= 1;

  i= i + 1;
  j= j + 1;
  printf("i: %d; j: %d\n", i, j);
}

int main(void) {
  f();
  f();
  f();

  return 0;
}
