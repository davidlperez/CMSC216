#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

int i, f, n;

int main(void) {
  scanf("%d", &n);
  f= 1;
  i= 1;
  while (i <= n)
    f *= i++;
  printf("%d\n", f);

  return 0;
}
