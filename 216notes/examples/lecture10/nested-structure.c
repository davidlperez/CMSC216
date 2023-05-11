#include <stdio.h>
#include <string.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* this example illustrates one structure that has another structure as a
 * member or field, and how to refer to fields of the inner structure
 */

/* note the enum inside the structure doesn't have to have a tag, because
   it has a field name */

typedef struct {
  enum { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC } month;
  int day;
  int year;
} Date;

typedef struct {
  int points;     /* how many points this project is worth */
  float weight;   /* this project's percentage to the course grade */
  Date due_date;  /* when you have to turn it in! */
} Project;

int main(void) {
  Project proj1, proj2;
  Project projects[11];

  proj1.points= 100;
  proj1.weight= 3.5;
  proj1.due_date.month= FEB;
  proj1.due_date.day= 9;
  proj1.due_date.year= 2023;

  proj2.points= 125;
  proj2.weight= 4.25;
  proj2.due_date.month= FEB;
  proj2.due_date.day= 17;
  proj2.due_date.year= 2023;

  projects[0]= proj1;  /* structure assignment */
  projects[1]= proj2;

  projects[2].points= 150;
  projects[2].weight= 4.5;
  projects[2].due_date.month= MAR;
  projects[2].due_date.day= 3;
  projects[2].due_date.year= 2023;

  printf("The third project is due %d/%d/%d.\n",
         projects[2].due_date.month + 1, projects[2].due_date.day,
         projects[2].due_date.year);

  return 0;
}
