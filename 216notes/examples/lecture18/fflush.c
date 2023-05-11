#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* This program illustrates one use of fflush(), in debugging, to ensure
 * that the output of debug printf() statements appears on the standard
 * output before a program crash.
 *
 * If you run the program as it is it will crash, and the output produced by
 * some debug print statements will be lost, because the output is left in
 * the output buffer when the program crashes, so you might think that the
 * program is crashing before the debug printf()s even execute.
 *
 * But if you uncomment the call to fflush() and compile and run the program
 * again, you will see all the debug print output before the foolish fatal
 * error.
 *
 * Note that the same effect can be achieved in this example (the debug
 * print output showing up before the crash) by adding newlines at the end
 * of each debug print statement.  But there are times that a program may
 * not be printing newlines and we still want pending output in the buffer
 * to appear, which we can cause to happen just using fflush().
 */

int main(void) {
  int x, y, z;

  printf("Kindly enter one number: ");
  scanf("%d", &x);

  printf("Please enter a second number: ");
  scanf("%d", &y);

  printf("Would you now enter your last number: ");
  scanf("%d", &z);

  /* the printf()s simulate various debugging print output that is being
     produced */
  x += y;
  printf("Debug print #1: x is %d ", x);

  y *= z;
  printf("Debug print #2: y is %d ", y);

  z++;
  printf("Debug print #3: z is %d ", z);

  x= y;
  
  /**/ fflush(stdout); /**/

  x= z / (y - x);

  printf("Debug print #4: x is now %d ", x);

  printf("x, y, and z are now %d, %d, and %d\n", x, y, z);

  return 0;
}
