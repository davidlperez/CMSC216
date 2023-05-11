#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Program where you need to type your function for the bitwise operator
 * coding exam question (#4) to verify that something that you lost credit
 * for was actually correct if you think that a mistake was made in grading,
 * *before* asking for the grading to be reconsidered.
 */

/* for simplicity it's assumed that no list will ever have enough elements
 * that a string containing the elements will be longer than this
 */
#define MAX_LEN 1000

typedef struct node {
  int data;
  struct node *next;
} Node;

typedef struct {
  Node *head;
  Node *tail;
} List;

static void init_list(List *list, int arr[], int size);
static void to_string(List list, char result[]);
static void clear(List *list);
static void check_list(List list, char result[]);
static void append(List *list, int n);  /* for testing */

/* store all elements of the array arr, which has size elements, into the
 * list that the first parameter points to, in the same order that they
 * appear in the array.
 */
void init_list(List *list, int arr[], int size) {
  Node *n;

  if (list != NULL && arr != NULL && size != 0) {

    list->head= list->tail= NULL;

    while (size-- > 0) {

      n= malloc(sizeof(*n));
      if (n != NULL) {
        n->data= arr[size];
        n->next= list->head;

        if (list->tail == NULL)
          list->tail= list->head= n;  /* empty list case */
        else list->head= n;
      }
    }
  }
}

/* uses sprintf() to create a string representation of the contents of the
 * list, to make comparisons of the list contents easier.  Note that things
 * could have been done more efficiently by comparing the list contents
 * without first converting the list to a string, but in this program we are
 * just concerned about correctness, not efficiency.
 */
void to_string(List list, char result[]) {
  char temp[MAX_LEN + 1];

  strcpy(result, "");  /* clear out any existing contents */

  while (list.head != NULL) {
    sprintf(temp, "%d", list.head->data);

    if (strlen(result) + strlen(temp) + 1 < MAX_LEN) {
      strcat(result, temp);

      /* add a space if it's not the last element */
      if (list.head->next != NULL)
        strcat(result, " ");
    }

    list.head= list.head->next;
  }
}

/* frees all dynamically allocated memory of the list that its parameter
   points to, and leaves the list head and tail pointers NULL */
void clear(List *list) {
  Node *temp;

  while (list != NULL && list->head != NULL) {
    temp= list->head;
    list->head= list->head->next;
    free(temp);
  }

  list->tail= NULL;
}

/* causes the program to quit if the contents of the list don't match the
 * string result, which must have a single space between the expected
 * values
 */
void check_list(List list, char result[]) {
  char elements[MAX_LEN + 1];

  to_string(list, elements);
  assert(strcmp(elements, result) == 0);
}

/* appends n to the end of the list that its first parameter points to */
void append(List *list, int n) {
  Node *new_node;

  if (list != NULL) {
    new_node= malloc(sizeof(*new_node));
    new_node->next= NULL;
    new_node->data= n;

    if (list->tail == NULL)
      list->head= list->tail= new_node;
    else list->tail= list->tail->next= new_node;
  }
}

/* remove the return statement below, then type your function in here */
unsigned short insert_every_other(List *list, int new_value) {
  return 1;
}

int main() {
  List list= {NULL, NULL};
  int arr[]= {10, 40, 20};

  init_list(&list, arr, sizeof(arr) / sizeof(arr[0]));

  /* test inserting an element every other element in a nonempty list */
  assert(insert_every_other(&list, 216) == 1);
  check_list(list, "10 216 40 216 20 216");

  /* test inserting an element every other element in another nonempty list */
  clear(&list);
  init_list(&list, arr, sizeof(arr) / sizeof(arr[0]));
  append(&list, 30);
  assert(insert_every_other(&list, 216) == 1);
  check_list(list, "10 216 40 216 20 216 30 216");

  /* test inserting an element every other element in a one-element list */
  clear(&list);
  append(&list, 1000);
  assert(insert_every_other(&list, 216) == 1);
  check_list(list, "1000 216");

  /* test inserting an element every other element in a two-element list */
  clear(&list);
  append(&list, 1000);
  append(&list, 2000);
  assert(insert_every_other(&list, 216) == 1);
  check_list(list, "1000 216 2000 216");

  /* test inserting an element every other element in an empty list, which
     should return 0 and not change the list */
  clear(&list);
  assert(insert_every_other(&list, 216) == 0);
  check_list(list, "");

  /* test calling the function on NULL, which should just return 0 (and
     should definitely not crash) */
  assert(insert_every_other(NULL, 1000) == 0);

  /* clean up the list contents, so valgrind will report that there are no
   * memory leaks, assuming that your insert_two_after() function doesn't
   * have any
   */
  clear(&list);

  printf("All assertions succeeded!\n");

  return 0;
}
