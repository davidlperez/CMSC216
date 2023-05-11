#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

#define SZ 5

/* New and improved version of a union used for storing a grade, inside a
 * structure, along with a tag field (an enum) that records which union
 * field is active.  Also has a function that operates one one of the
 * structures.
 */

typedef struct {
  /* these are enum constants, not the names of the types int, char, float */
  enum { INT, CHAR, FLOAT } type;
  union {
    int score;    /* using this field to store 0...100 */
    char letter;  /* using this field to store 'A'...'F' */
    float gpa;    /* using this field to store 0.0...4.0 */
  } value;
} Grade2;

static void print_grade(Grade2 grade);

int main(void) {
  Grade2 grades[SZ];
  int i;

  grades[0].value.score= 78;
  grades[0].type= INT;

  grades[1].value.letter= 'B';
  grades[1].type= CHAR;

  grades[2].value.gpa= 3.72;
  grades[2].type= FLOAT;

  grades[3].value.letter= 'C';
  grades[3].type= CHAR;

  grades[4].value.score= 92;
  grades[4].type= INT;

  for (i= 0; i < SZ; i++)
    print_grade(grades[i]);

  return 0;
}

static void print_grade(Grade2 grade) {
  switch (grade.type) {
    case INT:    printf("%d\n", grade.value.score);
                 break;
    case CHAR:   printf("%c\n", grade.value.letter);
                 break;
    case FLOAT:  printf("%f\n", grade.value.gpa);
                 break;
    default:     printf("huh???\n");
                 break;
  }
}
