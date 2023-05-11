#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

int n= 3;

static void f(void);

int main(void) {
  f();

  return 0;
}

static void f(void) {
  if (n > 0) {
    printf("%d", n);
    n--;
    f();
  }
}
