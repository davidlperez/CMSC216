#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <err.h>
#include <sysexits.h>
#include "safe-fork.h"

/* (c) A.U. Shankar and Larry Herman, 2023.  You are allowed to use this
   code yourself, but not to provide it to anyone else. */

/* Can be used to see why unused ends of a pipe need to be closed.
 *
 * Compile and run.  Then comment out the specified close() in the pipe
 * reader's code, compile, and run again.  What happens?
 *
 * This example doesn't show why the other close()s are needed, for example
 * the ones in the child code.  That would involve some other things we are
 * just omitting.  But there are cases where they would be necessary.
 */

int main(void) {
  pid_t pid;
  int pfd[2];

  /* the error case should not occur, but it does not hurt to assert that
     pipe() doesn't return -1 just in case something unexpected happens */
  assert(pipe(pfd) != -1);
  pid= safe_fork();

  if (pid > 0) {  /* parent */
    char ch;

    /* set stdin to pipe's read end */
    dup2(pfd[0], STDIN_FILENO);
    close(pfd[0]);
    /* after running, comment out the following close and rerun */
    close(pfd[1]);

    /* read integers until EOF; they will come from the pipe and were
       printed by the child */
    while ((ch= getchar()) != EOF)
      printf("Parent received %c from child.\n", ch);

  } else
    if (pid == 0) {  /* child */
      char msg[]= "CMSC 216.";
      int i= 0;

      /* set stdout to pipe's write end */
      dup2(pfd[1], STDOUT_FILENO);
      close(pfd[0]);
      close(pfd[1]);

      /* print some data to standard output; it will go to the pipe and
         be available to be read by the parent */
      while (i < strlen(msg))
        printf("%c", msg[i++]);

    } else err(EX_OSERR, "fork error");

  return 0;
}
