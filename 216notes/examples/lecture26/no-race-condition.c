#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <assert.h>
#include <pthread.h>

/* This is the same example as race-condition.c, except with the race
 * condition having been fixed.  How else could the race condition have been
 * fixed as well?
 */

#define NUM_THREADS 4

typedef struct {
  int x, y;
} Point;

static void *print_point(void *arg);

static void *print_point(void *arg) {
  Point point= * (Point *) arg;

  free(arg);

  printf("(%d, %d)\n", point.x, point.y);

  return NULL;
}

int main(void) {
  pthread_t tids[NUM_THREADS];
  int i;
  Point *pt_ptr;

  for (i= 0; i < NUM_THREADS; i++) {
    pt_ptr= malloc(sizeof(*pt_ptr));
    assert(pt_ptr != NULL);
    pt_ptr->x= i;
    pt_ptr->y= 3 * i + 2;
    assert(pthread_create(&tids[i], NULL, print_point, pt_ptr) == 0);
  }

  for (i= 0; i < NUM_THREADS; i++)
    assert(pthread_join(tids[i], NULL) == 0);

  return 0;
}
