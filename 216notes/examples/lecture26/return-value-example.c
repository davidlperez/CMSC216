#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>

/* Illustrates how to have a thread return a value (assuming we don't want
 * to clobber the argument), that will persist even when the thread function
 * exits.  (What two things should we have really done in this example, if
 * it was a more realistic program, that we didn't do?)
 */

static void *get_rand_num(void *args);

static void *get_rand_num(void *args) {
  int *nump= malloc(sizeof(*nump));

  srand(pthread_self());
  *nump= rand();

  return nump;
}

int main(void) {
  pthread_t tid1, tid2;
  void *ptr1= NULL, *ptr2= NULL;

  assert(pthread_create(&tid1, NULL, get_rand_num, NULL) == 0);
  assert(pthread_create(&tid2, NULL, get_rand_num, NULL) == 0);

  assert(pthread_join(tid1, &ptr1) == 0);
  assert(pthread_join(tid2, &ptr2) == 0);

  printf("The random number returned by thread 0 is %d\n", * (int *) ptr1);
  printf("The random number returned by thread 1 is %d\n", * (int *) ptr2);

  return 0;
}
