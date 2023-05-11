#include <stdio.h>
#include <sys/types.h>  /* needed on the submit server to use pid_t */
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* This example just illustrates some different combinations of file modes,
 * and their effects on what happens.
 *
 * file.txt, file2.txt, and file3.txt are all identical.  They are all
 * opened twice below and the same characters are written to them; the
 * only difference is that they are opened with different modes.  See the
 * difference the modes make by looking at their contents after this
 * example is run.  (You may want to make copies of them first, because
 * they'll be modified, and you may want to compare their contents to the
 * originals to see what happened.)
 *
 * (Since the files file.txt, file2.txt, and file3.txt get modified by the
 *  program, you may want to recopy them from 216public after running the
 *  example, in case you want to run it again.)
 */

/* the same as 0666, but a bit more symbolic */
#define DEF_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(void) {
  int fd;
  char msg[]= "CMSC 216 makes me shiver with glee.";
  int i;

  for (i= 1; i <= 2; i++) {
    fd= open("file.txt", O_WRONLY | O_CREAT, DEF_MODE);
    if (fd == -1)
      perror("can't open file.txt for writing.");
    else {
      write(fd, msg, sizeof(msg));
      close(fd);
    }
  }

  for (i= 1; i <= 2; i++) {
    fd= open("file2.txt", O_WRONLY | O_TRUNC | O_CREAT, DEF_MODE);
    if (fd == -1)
      perror("can't open file.txt for writing.");
    else {
      write(fd, msg, sizeof(msg));
      close(fd);
    }
  }

  for (i= 1; i <= 2; i++) {
    fd= open("file3.txt", O_WRONLY | O_APPEND | O_CREAT, DEF_MODE);
    if (fd == -1)
      perror("can't open file3.txt for writing.");
    else {
      write(fd, msg, sizeof(msg));
      close(fd);
    }
  }

  fd= open("missing-file.txt", O_RDONLY);
  if (fd == -1)
    perror("can't open missing-file.txt for reading.");
  else close(fd);

  return 0;
}
