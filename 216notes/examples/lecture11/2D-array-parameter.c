#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* illustrates how a two-dimensional array parameter would be declared */

static int sum_array(int arr[][3], int num_rows);

static int sum_array(int arr[][3], int num_rows) {
  int i, j, sum= 0;

  for (i= 0; i < num_rows; i++)
    for (j= 0; j < 3; j++)
      sum += arr[i][j];

  return sum;
}

int main(void) {
  int arr1[4][3]= {{7, 5, 3}, {1, 8, 6}, {4, 2, 1}, {8, 6, 0}};
  int arr2[5][3]= {{7, 5}, {3, 1, 8}, {6}, {4, 2}};

  printf("%d\n", sum_array(arr1, 4));
  printf("%d\n", sum_array(arr2, 5));

  return 0;
}
