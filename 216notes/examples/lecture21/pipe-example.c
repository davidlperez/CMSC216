#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <err.h>
#include <sysexits.h>
#include "safe-fork.h"

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* This example illustrates two processes using a pipe to exchange data. */

int main(void) {
  pid_t pid;
  int pipefd[2];

  /* the error case should not occur, but it does not hurt to assert that
     pipe() doesn't return -1 just in case something unexpected happens */
  assert(pipe(pipefd) != -1);
  pid= safe_fork();

  if (pid > 0) {  /* parent */
    /* BUFSIZ is defined in stdio.h; it's the size of buffers that stdio.h
       uses */
    char buf[BUFSIZ];

    close(pipefd[1]);
    assert(read(pipefd[0], buf, BUFSIZ) != -1);

    close(pipefd[0]);

    printf("The critical message the parent received from the ");
    printf("child was\n'%s'.\n", buf);

  } else

    if (pid == 0) {  /* child */
      char message[]= "You must write your own tests of your project code!!!";

      close(pipefd[0]);
      printf("Child is sending crucial message to parent.\n");
      assert(write(pipefd[1], message, sizeof(message)) != -1);

      close(pipefd[1]);

    } else err(EX_OSERR, "fork error");

  return 0;
}
