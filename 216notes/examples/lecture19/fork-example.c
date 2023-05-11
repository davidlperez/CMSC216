#include <stdio.h>
#include <sys/types.h>  /* needed on the submit server to use pid_t */
#include <unistd.h>
#include <err.h>
#include <sysexits.h>
#include "safe-fork.h"

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* This program illustrates the use of fork(), and the fact that the parent
 * and child processes have independent memory after the fork() (their
 * variables are different).  sleep(5) is just so we're sure the child is
 * printing x after the parent has incremented x, and we can see that the
 * child's x value is different from the parent's x value- because although
 * the child starts with a copy of the parent's memory, both processes have
 * independent memory.
 */

int main(void) {
  int x= 216;
  pid_t child_pid;

  child_pid= safe_fork();

  if (child_pid > 0) {  /* this is the parent code */

    printf("I am the parent (%d).  My child is %d.\n", getpid(), child_pid);
    x++;
    printf("Parent x value is %d.\n", x);

  } else

    if (child_pid == 0) {  /* this is the child code */

      printf("I am the child (%d).  My parent is %d.\n", getpid(), getppid());
      sleep(5);
      printf("Child process exiting.  Child x value is %d.\n", x);

    } else err(EX_OSERR, "fork error");  /* error case; child_pid == -1 */

  return 0;
}
