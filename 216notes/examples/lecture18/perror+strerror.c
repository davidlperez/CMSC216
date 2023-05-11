#include <stdio.h>
#include <string.h>
#include <errno.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* illustrates both perror() and strerror() */

int main(void) {
  /* this file doesn't exist, so trying to open it will be an error */
  FILE *fp= fopen("banana", "r");
  char message[100]= "\nThis is your robot overlord!  Error detected was: ";

  /* perror() prints a description of the last error seen during a system
     call or library function, preceded by the argument string */
  perror("In main, error seen is");

  /* an invalid mode, so this is also an error */
  fp= fopen("banana", "q");

  /* strerror() returns a string describing the last error seen during a
   * system call or library function, if instead of just printing the error
   * (like perror() would do) you want to manipulate the string using the
   * string library functions.  Here we use strcat() to append it to another
   * string, which we then print.
   */
  strcat(message, strerror(errno));
  puts(message);

  if (fp != NULL)
    fclose(fp);

  return 0;
}
