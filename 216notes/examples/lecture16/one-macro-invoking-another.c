#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Just illustrates that one macro can invoke another one. */

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define LARGEST(w, x, y, z) MAX(MAX(w, x), MAX(y, z))

int main(void) {
  int v1, v2, v3, v4;

  printf("Kindly enter four integers: ");
  scanf("%d%d%d%d", &v1, &v2, &v3, &v4);

  printf("The largest of the four numbers %d, %d, %d, and %d is %d.\n",
         v1, v2, v3, v4, LARGEST(v1, v2, v3, v4));

  return 0;
}
