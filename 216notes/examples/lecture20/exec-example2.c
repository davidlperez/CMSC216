#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>  /* needed on the submit server to use pid_t */
#include <unistd.h>
#include <err.h>
#include <sysexits.h>
#include "safe-fork.h"

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Illustrates a program that forks a child, and has the child exec another
 * program (the ls program in this case).  The parent waits for the child to
 * terminate, then does some other processing afterward.  (OK, the other
 * processing is not all that exciting, but it demonstrates the point....)
 */

int main(void) {
  pid_t child_pid;

  child_pid= safe_fork();

  if (child_pid > 0) {

    wait(NULL);  /* NULL means we don't care about the child's exit status */
    printf("\nI am the parent.  My child was %d.\n", child_pid);

  } else
    if (child_pid == 0) {  /* this is the child code */

      printf("I am the child (%d).\n", getpid());
      printf("Now replacing myself with \"ls -l -a -F\".\n\n");

      /* the 'l' forms of exec (like execlp()) require that each argument
       * you want to pass to the exec'ed program be passed SEPARATELY.  In
       * other words, execle("/bin/ls", "ls -l -a -F", NULL) and
       * execle("/bin/ls", "ls", "-l -a -F", NULL) are both borked- the
       * first of these won't work at all and the second one won't work as
       * intended
       */
      execlp("ls", "ls", "-l", "-a", "-F", NULL);

      err(EX_OSERR, "exec error");  /* why no if statement? */

    } else err(EX_OSERR, "fork error");  /* error case; child_pid == -1 */

  return 0;
}
