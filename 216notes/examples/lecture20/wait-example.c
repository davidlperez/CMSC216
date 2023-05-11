#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>  /* needed on the submit server to use pid_t */
#include <sys/wait.h>
#include <unistd.h>
#include <err.h>
#include <sysexits.h>
#include "safe-fork.h"

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* This program illustrates that with the call to wait(), the child will
 * always print its message before the parent, because the wait() causes the
 * parent to wait, as its name implies.  This example also illustrates the
 * parent getting the child's exit code after the child terminates, which
 * wait() also allows it to do.
 */

int main(void) {
  pid_t child_pid;

  child_pid= safe_fork();

  if (child_pid > 0) {  /* this is the parent code */
    int status;
    /* the error case should not occur, but it does not hurt to assert that
       wait() doesn't return -1 just in case something unexpected happens */
    assert(wait(&status) != -1);

    printf("Parent pid is %d; my child had pid %d.\n", getpid(), child_pid);

    /* note that the child process exit status is NOT just the value of the
       variable status, whose address was passed into wait(); its exit
       status must be obtained by calling WEXITSTATUS(status) */
    if (WIFEXITED(status))
      printf("Child exited with status %d.\n", WEXITSTATUS(status));
    else printf("Child was seriously borked; did not terminate normally.\n");

  } else
    if (child_pid == 0) {  /* this is the child code */

      printf("Child pid is %d; my parent has pid %d.\n", getpid(),
             getppid());
      exit(2);  /* just to illustrate, the child exits with status 2 */

    } else err(EX_OSERR, "fork error");  /* error case; child_pid == -1 */

  return 0;
}
