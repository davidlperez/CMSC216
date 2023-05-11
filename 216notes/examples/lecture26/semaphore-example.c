#include <stdio.h>
#include <assert.h>
#include <pthread.h>
#include <semaphore.h>

/* This is the same example as no-synchronization.c, except with a semaphore
 * used to ensure that the increments to the variable count are performed
 * atomically.
 */

#define LOOPS 10000000  /* 10 million */

/* look, we used more global variables!  (be sure you realize why) */
int count= 0;
sem_t mutex;

static void *counter(void *args);

static void *counter(void *args) {
  int i;

  for (i= 0; i < LOOPS; i++) {
    assert(sem_wait(&mutex) == 0);
    count= count + 1;
    assert(sem_post(&mutex) == 0);
  }

  printf("counter() loop executed %d times.\n", i);

  return NULL;
}

int main(void) {
  pthread_t tids[2];

  assert(sem_init(&mutex, 0, 1) == 0);

  assert(pthread_create(&tids[0], NULL, counter, NULL) == 0);
  assert(pthread_create(&tids[1], NULL, counter, NULL) == 0);

  assert(pthread_join(tids[0], NULL) == 0);
  assert(pthread_join(tids[1], NULL) == 0);

  printf("The variable count is now %d.\n", count);

  return 0;
}
