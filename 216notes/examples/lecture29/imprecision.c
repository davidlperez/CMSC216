#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Illustrates imprecision with real numbers */

int main(void) {
  float f= 1111111111.0;

  if (f + 1 == 1111111168.0)
    printf("equal\n");
  else printf("not equal\n");

  return 0;
}
