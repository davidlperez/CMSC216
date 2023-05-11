#include <stdio.h>
#include <sys/types.h>  /* needed on the submit server to use pid_t */
#include <sys/wait.h>
#include <unistd.h>
#include <err.h>
#include <sysexits.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Illustrates a program calling exec to replace itself, in the current
 * process, with another program (the ls program in this case).
 *
 * Note that the ls program (which is being exec'ed) pays attention to some
 * environment variables (it tailors its output depending on their values),
 * so we can pass the current environment to it in case the user running
 * this program has set any of those environment variables.
 *
 * If you are exec'ing some program that does not use environment variables
 * though then there is no reason at all to pass the environment to it
 * (meaning there is no reason to use execve(), execvpe(), or execle()).
 */

extern char **environ;

int main(void) {
  printf("I have just come to life.  My PID is %d, ", getpid());
  printf("and my parent is %d.\n", getppid());
  printf("I have accomplished what I wanted to in life, ");
  printf("so I am ready to be replaced.\n");
  printf("PID %d replacing myself.\n\n", getpid());

  /* the 'l' forms of exec (like execle()) require that each argument you
   * want to pass to the exec'ed program be passed SEPARATELY.  In other
   * words, execle("/bin/ls", "ls -l", NULL, environ) is borked and won't
   * work
   */
  execle("/bin/ls", "ls", "-l", NULL, environ);
  err(EX_OSERR, "exec error");  /* why no if statement? */

  return 0;
}
