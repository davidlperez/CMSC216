#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* This is the same program as simple-condition-synchronization.c shown last
 * time, except the first two statements in the withdrawal_thread() function
 * have been swapped or reversed (the two sem_wait() calls).  This can have
 * an unfortunate (calamitous) effect on the program's results (although the
 * program could possibly work fine).
 */

int bank_balance= 0;
sem_t mutex;
sem_t can_withdraw;

static void *withdrawal_thread(void *arg);
static void *deposit_thread(void *arg);

static void *withdrawal_thread(void *arg) {
  int i;

  for (i= 1; i <= 25; i++) {
    assert(sem_wait(&mutex) == 0);

    /* wait if balance is ever zero */
    assert(sem_wait(&can_withdraw) == 0);

    bank_balance -= 10;
    printf("Withdrawal thread is deducting $10 from the balance; ");
    printf("new balance is %d.\n", bank_balance);

    assert(sem_post(&mutex) == 0);

    sleep(rand() % 2 == 0);  /* delay 1 second 50% of the time */
  }

  return NULL;
}

static void *deposit_thread(void *arg) {
  int i;

  for (i= 1; i <= 25; i++) {
    assert(sem_wait(&mutex) == 0);

    bank_balance += 10;
    printf("Deposit thread is adding $10 to the balance; new balance is %d.\n",
           bank_balance);

    assert(sem_post(&mutex) == 0);

    /* wake up withdrawing thread after adding money */
    assert(sem_post(&can_withdraw) == 0);

    sleep(rand() % 2 == 0);  /* delay 1 second 50% of the time */
  }

  return NULL;
}  
    
int main(void) {
  pthread_t deposit_thread_tid, withdrawal_thread_tid;

  /* seed the random number generator so it's, well, really random */
  srand(time(NULL));

  /* note the initialization of the semaphores */
  assert(sem_init(&mutex, 0, 1) == 0);
  assert(sem_init(&can_withdraw, 0, 0) == 0);

  assert(pthread_create(&deposit_thread_tid, NULL, deposit_thread,
                        NULL) == 0);
  assert(pthread_create(&withdrawal_thread_tid, NULL, withdrawal_thread,
                        NULL) == 0);

  assert(pthread_join(withdrawal_thread_tid, NULL) == 0);
  assert(pthread_join(deposit_thread_tid, NULL) == 0);

  printf("\nThe final account balance is $%d.\n", bank_balance);

  return 0;
}
