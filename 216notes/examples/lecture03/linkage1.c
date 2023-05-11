#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Illustrates linkage and changing linkage.
 *
 * The two parts of this program put together (in the files linkage1.c and
 * linkage2.c) form a complete program.
 *
 * Questions/exercises for the reader:
 *   - Trace the program and see if you get the right output (compile and run
 *     it to see). 
 *   - What happens if "extern" is removed from "extern int y" in main()
 *     below?
 *   - What happens if "static" is removed from one of the global variables x
 *     in either file, but not both?  And what happens if it's removed from
 *     the declarations of x in both files?
 */

static int f(int i);
void g(void);

static int x= 2;

static int f(int i) {
  printf("This is a different f() (and i is %d).\n", i);

  return 216;
}

int main(void) {
  extern int y;
  int z;

  y= 4;
  z= f(123);
  g();

  printf("In linkage1.c, x is %d and y is %d and z is %d.\n", x, y, z);

  return 0;
}
