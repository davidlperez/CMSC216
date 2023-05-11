#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* be sure you understand why the output of this program is what it is!
 */

typedef struct {
  int score;
  char letter;
  float gpa;
} Grade;

int main(void) {
  Grade grade;

  printf("The byte sizes of the three structure fields are %d, %d, and %d.\n",
         (int) sizeof(grade.score), (int) sizeof(grade.letter),
         (int) sizeof(grade.gpa));
  printf("The byte size of the structure itself is %d.\n",
         (int) sizeof(grade));

  return 0;
}

