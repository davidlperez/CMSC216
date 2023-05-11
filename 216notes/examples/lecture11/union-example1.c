#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* demonstrates declaring a union, and also shows that nothing automatically
 * keeps track of which union field or variant is in use
 */

typedef union {
  int score;    /* using this field to store 0...100 */
  char letter;  /* using this field to store 'A'...'F' */
  float gpa;    /* using this field to store 0.0...4.0 */
} Grade;

int main(void) {
  Grade grades[5];

  grades[0].letter= 'B';
  grades[1].score= 90;
  grades[2].gpa= 3.25;
  grades[3].score= 77;
  grades[4].letter= 'A';

  printf("%c\n", grades[0].letter);
  printf("%d\n", grades[1].score);

  printf("%d\n", grades[0].score);
  printf("%d\n", grades[2].score);

  /* we stored something in the int field of grades[1], now let's store
     something in the float field of grades[1] instead- we can change which
     field of a union is assigned to used */
  grades[1].gpa= 2.75;
  printf("%.2f\n", grades[1].gpa);

  /* but if we try to use the int field of grades[1] now, after storing
     something in its float field, we see that the four bytes of the int
     were overwritten by the float, so it has an unpredictable value, and is
     clearly not 90 any more (we would have to know how floats are stored in
     memory to figure out why its value is now as it is) */
  printf("%d\n", grades[1].score);

  printf("\nThe byte sizes of the three union fields are %d, %d, and %d.\n",
         (int) sizeof(grades[0].score), (int) sizeof(grades[0].letter),
         (int) sizeof(grades[0].gpa));
  printf("The byte size of the union itself is %d.\n", (int)
         sizeof(grades[0]));

  return 0;
}
