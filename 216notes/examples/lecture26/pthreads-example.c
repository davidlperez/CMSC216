#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <pthread.h>

/* Illustrates the indeterminate order of thread execution, and saving
 * thread IDs in order to be able to reap them later via pthread_join().
 * Why in class did we say that an array ids has to be used (why not just
 * pass &i as the last argument to pthread_create())?
 */

#define THREAD_CT 2  /* bump this up a few numbers if you like */

static void *print_stuff(void *ptr);

static void *print_stuff(void *ptr) {
  int i, id;

  if (ptr != NULL) {
    id= * (int *) ptr;

    for (i= 0; i < 5; i++) {
      printf("Thread %d is executing loop iteration %d.\n", id, i);
      sleep(rand() % 2);  /* sleep for either 0 or 1 seconds */
    }

    printf("Thread %d is exiting.\n", id);
  }

  return NULL;
}

int main(void) {
  pthread_t tids[THREAD_CT];
  int i, ids[THREAD_CT];

  for (i= 0; i < THREAD_CT; i++) {
    ids[i]= i;
    assert(pthread_create(&tids[i], NULL, print_stuff, &ids[i]) == 0);
    printf("Main thread created thread %d (ID %ld).\n", i, tids[i]);
  }

  for (i= 0; i < THREAD_CT; i++) {
    assert(pthread_join(tids[i], NULL) == 0);
    printf("Main thread reaped thread %d (ID %ld).\n", i, tids[i]);
  }

  return 0;
}
