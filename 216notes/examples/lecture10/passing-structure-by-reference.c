#include <stdio.h>
#include <string.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* This example illustrates a function that has a pointer to a structure as
 * a parameter, which accesses (modifies in this case) the structure that
 * the pointer points to.  Unless the structure is very small it's more
 * efficient to pass a pointer to a structure than just passing the
 * structure (why?).
 */

/* note the enum inside the structure doesn't have to have a tag,
   because it has a field name */
typedef struct {
  enum { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT,
         NOV, DEC } month;
  int day;
  int year;
} Date;

typedef struct {
  int points;     /* how many points this project is worth */
  float weight;   /* this project's percentage to the course grade */
  Date due_date;  /* when you have to turn it in! */
} Project;

static void change_weight(Project *project, float new_weight);

/* now a void function, unlike the example structure function in the
   earlier example */
static void change_weight(Project *project, float new_weight) {
  if (new_weight > 0)
    project->weight= new_weight;
}

int main(void) {
  Project proj2, proj3;

  proj2.points= 125;
  proj2.weight= 4.25;
  proj2.due_date.month= FEB;
  proj2.due_date.day= 27;
  proj2.due_date.year= 2023;

  proj3= proj2;

  printf("proj3 is %d points, worth %f, and due %d/%d/%d.\n",
         proj3.points, proj3.weight, proj3.due_date.month + 1,
         proj3.due_date.day, proj3.due_date.year);

  change_weight(&proj3, 3.75);

  printf("proj3 is %d points, now worth %f, and due %d/%d/%d.\n",
         proj3.points, proj3.weight, proj3.due_date.month + 1,
         proj3.due_date.day, proj3.due_date.year);

  return 0;
}
