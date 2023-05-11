#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Illustrates that as long as a program is syntactically valid after macro
 * substitution is performed, the macro is valid.  (Note that this is
 * intentionally an ugly example.  Do not emulate our style by writing
 * macros like this.)
 */

#define WEIRD(x) * x

int f(int y, int z) {
  return y WEIRD(z);
}

int main(void) {
  int i= 5;
  int *p= &i;

  printf("%d %d\n", f(3, 4), WEIRD(p));

  return 0;
}
