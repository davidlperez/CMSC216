#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* illustrates linkage and changing linkage */

/* the two parts of this program put together (in the files linkage1.c and
   linkage2.c) form a complete program */

static void f(int i);
void g(void);

static int x= 1;
int y= 3;

static void f(int i) {
  printf("In linkage2.c, x is %d, y is %d, and i is %d.\n", x, y, i);
}

void g(void) {
  f(456);
}
