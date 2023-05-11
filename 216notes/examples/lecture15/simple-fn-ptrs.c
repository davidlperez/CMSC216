#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* A simple illustration of basic function pointer mechanics and
 * alternatives.
 */

static void f(int a);

void f(int a) {
  printf("My parameter is %d.\n", a);
}

int main(void) {
  void (*int_func)(int);

  /* you can make a function pointer point to a function this way */
  int_func= f;
  /* you can call a function through a function pointer that is pointing to
     it this way */
  int_func(2);

  /* or you can make a function pointer point to a function this way (no
     difference in effect, just an alternate syntax; it is just a little
     more explicit) */
  int_func= &f;
  /* or you can call a function through a function pointer that is pointing
     to it this way (no difference in effect, just an alternate syntax; it
     is just a little more explicit) */
  (int_func)(3);

  /* or you can even call a function through a function pointer that is
     pointing to it this way (no difference in effect, just an alternate
     syntax; it is just a little more explicit) */
  (*int_func)(4);

  return 0;
}
