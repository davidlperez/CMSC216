#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* has two functions with array parameters- notice use of const, both with
   an array parameter and a pointer parameter */

static int find(const int data[], int size, int value);
static void remove_first(int arr[], int *const size);

/* returns the index where value was found in the array, or -1 if not
   found */
static int find(const int data[], int size, int value) {
  int i= 0, ans= -1;

  while (i < size && ans == -1) {
    if (data[i] == value)
      ans= i;
    i++;
  }

  return ans;
}

/* remove_first() removes s all elements one position earlier in the array,
   "removing" the first one; the array's size decreases by 1 as a result */
static void remove_first(int arr[], int *const size) {
  int i;

  (*size)--;

  for (i= 0; i < *size; i++)
    arr[i]= arr[i + 1];
}

int main(void) {
  int arr1[]= {2, 0, 2, 3};
  int arr2[]= {3, 6, 8, 2, 9, 4, 1, 5, 7};
  int num_elements_in_arr2= 9;

  printf("%d\n", find(arr1, 4, 1));
  printf("%d\n", find(arr2, num_elements_in_arr2, 5));
  printf("%d\n", find(arr2, num_elements_in_arr2, 10));

  remove_first(arr2, &num_elements_in_arr2);

  printf("%d\n", find(arr2, num_elements_in_arr2, 3));

  return 0;
}
