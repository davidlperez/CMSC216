#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>  /* needed on the submit server to use pid_t */
#include <sys/wait.h>
#include <unistd.h>
#include <err.h>
#include <sysexits.h>
#include "safe-fork.h"

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* This program illustrates that without a wait, the execution order of the
 * parent and child processes are indeterminate.  Although the parent prints
 * first more often, if you run the program several times you will see *
 * some cases where each process prints first.
 *
 * (The srand() and sleep() calls introduce a small random delay in both the
 * parent and the child, before the print, since without this the parent
 * process, which is currently executing when the child is created, would
 * most likely always finish before the child starts in almost every case,
 * since it only has a small amount of code to execute after the child is
 * created- this program is artificially small.  You may still have to run
 * it several times to see different output orders.  Your TA may explain in
 * discussion section why the srand() and sleep() calls are written the way
 * they are.)
 */

int main(void) {
  pid_t child_pid;

  child_pid= safe_fork();

  srand(time(NULL) + getpid());
  sleep(rand() % 3);

  if (child_pid > 0)  /* this is the parent code */

    printf("Parent pid is %d; my child has pid %d.\n", getpid(), child_pid);

  else
    if (child_pid == 0)  /* this is the child code */

      printf("Child pid is %d; my parent has pid %d.\n", getpid(), getppid());

    else err(EX_OSERR, "fork error");  /* error case; child_pid == -1 */

  return 0;
}
