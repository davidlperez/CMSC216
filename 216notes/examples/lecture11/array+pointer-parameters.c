#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* shows passing an array and a pointer into an array parameter and a
   pointer parameter, and illustrates exactly what gets passed */
 
static void f(const int a[]);
static void g(const int *a);

static void f(const int a[]) {
  printf("%d %d %d\n", a[0], *a, (int) sizeof(a));
}
 
static void g(const int *a) {
  printf("%d %d %d\n", a[0], *a, (int) sizeof(a));
}
 
int main(void) {
  int arr[5]= {3, 5, 7, 9, 11};
  int *p= &arr[0];
 
  printf("%d %d\n", (int) sizeof(arr), (int) sizeof(p));

  f(arr);
  g(arr);
 
  f(p);
  g(p);
 
  return 0;
}
