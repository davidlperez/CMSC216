#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

#if !(defined(SIZE))
#define SIZE 10
#endif

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/* Here is a great comment which describes how interesting both this
   program, as well as all of the CMSC 216 lectures, are.  Look for me again
   after preprocsssing! */

int main(void) {
  int x, y;

  printf("SIZE is %d.\n", SIZE);

  scanf("%d%d", &x, &y);
  printf("The maximum of x and y (MAX(x, y)) is %d.\n", MAX(x, y));

  #if defined(DEBUG)
  printf("Suppose the fine program prints extra debugging info here.\n");
  #endif

  return 0;
}
