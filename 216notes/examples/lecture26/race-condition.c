#include <stdio.h>
#include <assert.h>
#include <pthread.h>

/* In this program four threads each print the coordinate of a different
 * point along a line.  It doesn't matter what order the four points are
 * printed in.  There is a race condition- what is it, and why does it
 * occur?  (Try running the program (maybe several times) to see what's
 * wrong, which should help in figuring things out.)
 */

#define NUM_THREADS 4

typedef struct {
  int x, y;
} Point;

static void *print_point(void *arg);

static void *print_point(void *arg) {
  Point point= * (Point *) arg;

  printf("(%d, %d)\n", point.x, point.y);

  return NULL;
}

int main(void) {
  pthread_t tids[NUM_THREADS];
  int i;
  Point pt;

  for (i= 0; i < NUM_THREADS; i++) {
    pt.x= i;
    pt.y= 3 * i + 2;
    assert(pthread_create(&tids[i], NULL, print_point, &pt) == 0);
  }

  for (i= 0; i < NUM_THREADS; i++)
    assert(pthread_join(tids[i], NULL) == 0);

  return 0;
}
