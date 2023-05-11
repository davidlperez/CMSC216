#include <stdio.h>
#include <string.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* This program just illustrates a program performing basic access of its
   command-line arguments. */

int main(int argc, char *argv[]) {
  int i;

  printf("Hello, my name is %s.\n", argv[0]);

  if (argc == 1) {
    printf("You did not run me with any command-line arguments.  (I am " );
    printf("lonely.)\n");
  } else {
    printf("You ran me with these %d command-line argument(s):\n", argc - 1);
    for (i= 1; i < argc; i++)
      printf("  %s\n", argv[i]);
  }

  return 0;
}
