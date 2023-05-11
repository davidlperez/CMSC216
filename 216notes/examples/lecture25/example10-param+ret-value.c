#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

static int f(int i);

int main(void) {
  static int n;

  n= f(15);

  printf("%d", n);
  printf("\n");

  return 0;
}

static int f(int i) {
  return i * 10;
}
