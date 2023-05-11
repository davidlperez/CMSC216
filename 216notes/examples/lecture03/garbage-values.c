#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* illustrates that uninitialized variables have garbage values- they *may*
   start out with zero, *or* with any other value, if used without first
   being given a value somehow */

/* Note that although this program is valid C, with the compilation options
 * we're using for this course it will give a warning, and the warning will
 * prevent it from compiling.  To compile it without the compilation
 * options, instead of a command like
 *
 * gcc garbage-value.c -o garbage-value.x
 *
 * just put a backslash before gcc, as in
 *
 * \gcc garbage-value.c -o garbage-value.x
 */

int f(void);
void g(void);

/* the return value of f() isn't even being used where it's called in this
   program; it's returning a value just to show that values are returned
   from functions the same in C as in Java */
int f(void) {
  float num= 2.16;

  printf("num is %f\n", num);

  return 1;
}

void g(void) {
  int j;  /* uninitialized!!! */

  printf("j is %d\n", j);
}

int main(void) {
  int i;  /* uninitialized!!! */

  printf("i is %d\n", i);

  f();
  g();

  return 0;
}
