#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

int n= 2;

static void f(void);
static void g(void);

int main(void) {
  f();
  n= 1;
  g();

  return 0;
}

static void f(void) {
  g();
}

static void g(void) {
  while (n > 0)
    printf("%d", n--);
}
