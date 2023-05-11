#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* illustrates what can be done if a function has pointer(s) as parameters */

static void swap(int *x, int *y);

static void swap(int *x, int *y) {
  int tmp= *x;
  *x= *y;
  *y= tmp;
}

int main(void) {
  int a= 216, b= 250;
  int *p= &a, *q= &b;

  printf("a is %d and b is %d.\n", a, b);

  swap(p, q);

  printf("a is %d and b is %d.\n", a, b);

  return 0;
}
