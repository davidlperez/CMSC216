#include <stdio.h>

/* (c) Larry Herman and A.U. Shankar, 2023.  You are allowed to use this
   code yourself, but not to provide it to anyone else. */

/* A slightly larger function pointer example. */

static int square(int n);
static int cube(int n);
static void call_fn(int (*fp)(int), int arg);
static void cmp(int (*f)(int), int (*g)(int), int arg);

int square(int n) {
  return n * n;
}

int cube(int n) {
  return n * n * n;
}

int main(void) {
  int (*ptr)(int);

  ptr= square;
  printf("%d\n", (*ptr)(4));

  ptr= cube;
  printf("%d\n\n", (*ptr)(4));

  call_fn(square, 3);
  call_fn(cube, 3);
  printf("\n");

  cmp(cube, square, 1);
  cmp(cube, square, 3);

  return 0;
}

/* oh my gosh, what is this doing??? */
void call_fn(int (*fp)(int), int arg) {
  printf("%d\n", (*fp)(arg));
}

void cmp(int (*f)(int), int (*g)(int), int arg) {
  printf("%d\n", (*f)(arg) - (*g)(arg));
  /* or use printf("%d\n", f(arg) - g(arg)); */
}
