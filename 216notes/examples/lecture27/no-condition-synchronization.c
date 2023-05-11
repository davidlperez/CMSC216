#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* This program has two threads sharing a bank account, which is a simple
 * integer variable representing the amount of money in the account.  One
 * thread is depositing money ($250, $10 at a time) and the other is
 * concurrently withdrawing money (also $250, $10 at a time).  Without any
 * synchronization other than mutual exclusion, nothing prevents the balance
 * from becoming negative just due to the possible relative execution order
 * of the threads.  Note that the semaphore mutex enforces mutual exclusion,
 * but it does not prevent this problem.
 *
 * See the "fixed" version of this example in
 * simple-condition-synchronization.c.
 */

/* it's not necessary to use a global variable here; we just do it just to
 * avoid having to pass parameters to the threads, to keep the example
 * simpler
 */
int bank_balance= 0;
sem_t mutex;

static void *withdrawal_thread(void *arg);
static void *deposit_thread(void *arg);

static void *withdrawal_thread(void *arg) {
  int i;

  for (i= 1; i <= 25; i++) {
    assert(sem_wait(&mutex) == 0);

    bank_balance -= 10;
    printf("Withdrawal thread is deducting $10 from the balance; ");
    printf("new balance is %d.\n", bank_balance);

    assert(sem_post(&mutex) == 0);

    sleep(rand() % 2 == 0);  /* delay 1 second 20% of the time */
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

    sleep(rand() % 2 == 0);  /* delay 1 second 20% of the time */
  }

  return NULL;
}  
    
int main(void) {
  pthread_t deposit_thread_tid, withdrawal_thread_tid;

  srand(time(NULL));

  /* note the initialization of the semaphore */
  assert(sem_init(&mutex, 0, 1) == 0);

  assert(pthread_create(&deposit_thread_tid, NULL, deposit_thread,
                        NULL) == 0);
  assert(pthread_create(&withdrawal_thread_tid, NULL, withdrawal_thread,
                        NULL) == 0);

  assert(pthread_join(withdrawal_thread_tid, NULL) == 0);
  assert(pthread_join(deposit_thread_tid, NULL) == 0);

  printf("\nThe final account balance is $%d.\n", bank_balance);

  return 0;
}
