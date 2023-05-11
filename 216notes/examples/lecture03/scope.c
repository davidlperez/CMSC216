#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* illustrates file scope, block scope, and shadowing */

void f(void);

int a= 1;

int main(void) {
  int a= 2;

  printf("a in main() before the block is %d.\n", a);

  {
    int a= 3;
    printf("a in main after the block is %d.\n", a);
    /* call function f() below */
    f();
  }

  printf("a in main() after the block is %d.\n", a);

  return 0;
}

void f(void) {
  printf("a in function f() is %d.\n", a);
}
