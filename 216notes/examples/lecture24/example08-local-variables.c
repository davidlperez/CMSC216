#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

static void f(void);
static void g(void);

int main(void) {
  f();
  return 0;
}

static void f(void) {
  int x;

  x= 16;
  g();
  printf("%d", x);
}

static void g(void) {
  int a, b, c;

  a= 30;
  b= 25;
  c= a + b;
  printf("%d", c);
}
