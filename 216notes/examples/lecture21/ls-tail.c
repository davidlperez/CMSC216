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

/* Illustrates the motivation for redirecting I/O.  This program forks a
 * child process, then both parent and child replace themselves (exec) other
 * programs, after redirecting their input and output.  The effect is that
 * the output of the ls program exec'ed by the child goes to the input of
 * the tail program exec'ed by the parent, because both have redirected
 * their output and input respectively to the output and input ends of a
 * pipe.  We are able to run other programs and have their output go to
 * different places, without those programs even knowing about it (without
 * having to modify their code).  It would also be possible for example for
 * the parent to fork a child, have the child run (exec) another program,
 * and have the parent capture its output (again via a pipe dup2()), and
 * process it however it wanted after reading it from the pipe.  (Meaning
 * that instead of both processes exec'ing to replace themselves with
 * another program, only one of them could have.)
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

    assert(dup2(pipefd[0], STDIN_FILENO) != -1);
    assert(close(pipefd[0]) != -1);
    assert(close(pipefd[1]) != -1);
    execl("/usr/bin/tail", "tail", "-3", NULL);
    err(EX_OSERR, "execl error");

  } else

    if (pid == 0) {  /* child */

      assert(dup2(pipefd[1], STDOUT_FILENO) != -1);
      assert(close(pipefd[0]) != -1);
      assert(close(pipefd[1]) != -1);
      execl("/bin/ls", "ls", NULL);
      err(EX_OSERR, "execl error");

    } else err(EX_OSERR, "fork error");

  return 0;
}
