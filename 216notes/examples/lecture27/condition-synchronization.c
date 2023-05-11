#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Illustrates condition synchronization, as well as mutual exclusion.  Four
 * threads use a bounded buffer to exchange data; two producers add data
 * items to the buffer (using a circular array for a queue, of size 10),
 * while two consumers are removing data items from the queue and using them
 * in some way.  (One producer stores even values in the queue, the other
 * stores odd values.)  We just simulate data items with integers, that are
 * just appended to the queue by the producers, and removed and printed by
 * the consumer.  Some realistic applications might continue infinitely, or
 * until the producers detect the end of some input; here the producers just
 * produce 50 items each and the consumers stop when each one has consumed
 * 50 items.
 *
 * Note that the problem requires not only mutual exclusion but also
 * condition synchronization.  Also note that the producers and consumers
 * never need to explicitly check the queue's size; the semaphores ensure
 * that the consumer doesn't remove something until the queue is nonempty,
 * and the producers don't add something until the queue is not full.
 *
 * We omitted assert() calls for all the semaphore functions just because we
 * added a lot of comments, and the assertions would make them harder to
 * read.  It is unlikely that the functions would have an error, but if they
 * do, we are aware that we will not get a helpful assertion message, and we
 * are prepared to make that sacrifice for pedagogical purposes.
 */

/* this is the size of the queue, meaning the maximum number of elements
 * that can be stored at a time.  the global variable "size" below will
 * always have the current number of elements being stored in the queue at
 * any point in time
 */
#define QUEUE_SZ 10

/* it's not necessary to use global variables here; we just do it just to
 * avoid having to pass multiple parameters to the threads, to keep the
 * example simpler
 */
int arr[QUEUE_SZ], front= 0, size= 0;
/* for mutual exclusion; to restrict manipulation of the variables above to
 * one thread at a time
 */
sem_t mutex;                /* for mutual exclusion of append and remove */
sem_t num_items;            /* tracks number of items in buffer */
sem_t num_spaces;           /* tracks number of empty spaces in buffer */

static void *producer(void *arg);
static void *consumer(void *arg);

/* a thread that is "producing" elements and adding them to the queue runs
   this function */
static void *producer(void *arg) {
  int id;   /* thread-local; producer id; also initial item produced */
  int i;    /* thread-local; stores item produced */

  id= *(int *) arg;

  for (i= id; i <= 100; i += 2) {
    /* placeholder for code producing item; simulated by the value of i */
    sem_wait(&num_spaces);           /* wait for at least one empty space */
    sem_wait(&mutex);                /* lock critical section */
    arr[(front + size) % QUEUE_SZ]= i;  /* append new item */
    size++;
    sem_post(&mutex);                /* release critical section */
    printf("Producer %d produced item %d.\n", id, i);
    sem_post(&num_items);            /* update number of items available */
    sleep(rand() % 5 == 0);          /* delay 1 second 20% of the time */
  }

  return NULL;
}

/* a thread that is removing elements from the queue and "consuming" them
   runs this function */
static void *consumer(void *arg) {
  int id;                            /* consumer id */
  int item, item_count= 0;

  id= *(int *) arg;

  while (item_count != 50) {         /* hardcoded termination value */
    sem_wait(&num_items);            /* wait for at least 1 item available */
    sem_wait(&mutex);                /* lock critical section */
    item= arr[front];                /* remove first item */
    item_count++;
    front= (front + 1) % QUEUE_SZ;
    size--;
    sem_post(&mutex);                /* release critical section */
    /* placeholder for code consuming item here */
    printf("Consumer %d consumed item %d.\n", id, item);
    sem_post(&num_spaces);           /* update number of empty spaces */
    sleep(rand() % 5 == 0);          /* delay 1 second 20% of the time */
  }

  return NULL;
}

int main(void) {
  pthread_t producer1_tid, producer2_tid, consumer1_tid, consumer2_tid;
  int id1= 1, id2= 2;  /* ids for producer threads and for consumer threads */

  srand(time(NULL));

  /* note the initialization of the semaphores */
  assert(sem_init(&mutex, 0, 1) == 0);
  assert(sem_init(&num_items, 0, 0) == 0);
  assert(sem_init(&num_spaces, 0, QUEUE_SZ) == 0);

  assert(pthread_create(&producer1_tid, NULL, producer, &id1) == 0);
  assert(pthread_create(&producer2_tid, NULL, producer, &id2) == 0);
  assert(pthread_create(&consumer1_tid, NULL, consumer, &id1) == 0);
  assert(pthread_create(&consumer2_tid, NULL, consumer, &id2) == 0);

  assert(pthread_join(producer1_tid, NULL) == 0);
  assert(pthread_join(producer2_tid, NULL) == 0);
  assert(pthread_join(consumer1_tid, NULL) == 0);
  assert(pthread_join(consumer2_tid, NULL) == 0);

  return 0;
}
