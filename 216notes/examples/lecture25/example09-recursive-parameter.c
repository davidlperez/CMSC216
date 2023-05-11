#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

static void f(int i);

int main(void) {
  f(5);
  printf("\n");

  return 0;
}

static void f(int i) {
  if (i > 1)
    f(i - 2);
  printf("%d", i);
}
