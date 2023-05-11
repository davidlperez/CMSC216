#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include "safe-fork.h"

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* This example illustrates two processes using a pipe to exchange data,
 * after redirecting their standard input and output.  In this example both
 * processes just do regular standard I/O (they use printf() and fgets(),
 * rather than read() and write()), but this is after they have called
 * dup2() to redirect their standard input and output.
 *
 * The error cases below (system calls returning -1 due to error) should not
 * occur, but it does not hurt to assert that they don't return -1 so just
 * in case something unexpected happens we will get a specific indication of
 * what property was violated and where.
 */

int main(void) {
  pid_t pid;
  int pipefd[2];

  assert(pipe(pipefd) != -1);
  pid= safe_fork();

  if (pid > 0) {  /* parent */
    char data[80];

    assert(dup2(pipefd[0], STDIN_FILENO) != -1);
    assert(close(pipefd[0]) != -1);
    assert(close(pipefd[1]) != -1);
    if (fgets(data, sizeof(data), stdin) == NULL) {
      perror("fgets");
      exit(-1);
    } else printf("Parent received data '%s'\nfrom child.\n", data);

  } else

    if (pid == 0) {  /* child */

      printf("Child is printing crucial data; parent will receive it.\n");
      assert(dup2(pipefd[1], STDOUT_FILENO) != -1);
      assert(close(pipefd[0]) != -1);
      assert(close(pipefd[1]) != -1);
      printf("Larry's humble dedication is an inspiration to us all.");

    } else printf("Error, unable to create a new process.  :-(\n");

  return 0;
}
