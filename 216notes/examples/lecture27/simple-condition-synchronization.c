#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* This is the "fixed" version of the example in
 * no-condition-synchronization.c.
 *
 * This program has two threads sharing a bank account, which is a simple
 * integer variable representing the amount of money in the account.  One
 * thread is depositing money ($250, $10 at a time) and the other is
 * concurrently withdrawing money (also $250, $10 at a time).  Because we
 * want to mimic reality and prevent nonexistent money from being withdrawn,
 * we need to enforce- in addition to mutual exclusion- condition
 * synchronization.  In particular, we have to prevent the withdrawing
 * thread from removing money if there is no money, until the depositing
 * thread has added enough money.
 */

/* it's not necessary to use a global variable here; we just do it just to
 * avoid having to pass parameters to the threads, to keep the example
 * simpler
 */
int bank_balance= 0;
sem_t mutex;
sem_t can_withdraw;

static void *withdrawal_thread(void *arg);
static void *deposit_thread(void *arg);

static void *withdrawal_thread(void *arg) {
  int i;

  for (i= 1; i <= 25; i++) {
    assert(sem_wait(&can_withdraw) == 0);  /* wait if balance is ever zero */

    assert(sem_wait(&mutex) == 0);

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

  srand(time(NULL));

  /* note the initialization of the semaphores */
  assert(sem_init(&mutex, 0, 1));
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
