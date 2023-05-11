#include <stdio.h>
#include <assert.h>
#include <pthread.h>

/* Illustrates that when multiple threads access and modify a shared
 * variable (at least one of them is modifying it) concurrently,
 * inconsistent or unpredictable results can occur if no synchronization is
 * used.  (It may be analogous to an example that was probably shown in CMSC
 * 132, just in C using Pthreads here.)
 */

#define LOOPS 10000000  /* 10 million */

int count= 0;  /* look, we used a global variable!  (why?) */

static void *counter(void *args);

static void *counter(void *args) {
  int i;

  for (i= 0; i < LOOPS; i++)
    count= count + 1;

  printf("counter() loop executed %d times.\n", i);

  return NULL;
}

int main(void) {
  pthread_t tids[2];

  assert(pthread_create(&tids[0], NULL, counter, NULL) == 0);
  assert(pthread_create(&tids[1], NULL, counter, NULL) == 0);

  assert(pthread_join(tids[0], NULL) == 0);
  assert(pthread_join(tids[1], NULL) == 0);

  printf("The variable count is now %d.\n", count);

  return 0;
}
