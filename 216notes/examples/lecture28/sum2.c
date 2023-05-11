#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

/* Sums all the elements of a large array in one order, which is much faster
 * than the other version of this example, cache1.c.  Note that only the
 * order of the two nested loops is different in the two versions.  Why is
 * there a difference?
 */

#define ROWS 30000
#define COLS 30000

int main(void) {
  static int arr[ROWS][COLS];
  int i, j;
  long sum= 0;
  struct rusage usage1, usage2;

  for (i= 0; i < ROWS; i++)
    for (j= 0; j < COLS; j++)
      arr[i][j]= rand();

  getrusage(RUSAGE_SELF, &usage1);

  for (i= 0; i < ROWS; i++)
    for (j= 0; j < COLS; j++)
      sum += arr[i][j];

  getrusage(RUSAGE_SELF, &usage2);

  printf("sum is %ld.\n", sum);

  /* calculate user time difference in the variable usage2 */
  usage2.ru_utime.tv_sec -= usage1.ru_utime.tv_sec;
  if ((usage2.ru_utime.tv_usec -= usage1.ru_utime.tv_usec) < 0) {
    usage2.ru_utime.tv_usec += 1000000;
    usage2.ru_utime.tv_sec--;
  }
  printf("Time spent executing in user mode was %d.%06ds\n",
         (int) usage2.ru_utime.tv_sec, (int) usage2.ru_utime.tv_usec);

  return 0;
}
