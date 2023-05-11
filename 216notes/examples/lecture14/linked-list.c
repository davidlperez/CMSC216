#include <stdio.h>
#include <stdlib.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Illustrates some linked list operations in C, for an ordered,
 * singly-linked list (the insert() function creates an ordered
 * list). Compare to Java.  Practice- write the find() function that the
 * commented-out code in main() is calling, uncomment the calls to it, and
 * make sure it works.
 */

typedef struct node {
  int data;
  struct node *next;
} Node;

static int insert(Node **head, int value);
static int delete(Node **head, int value);

/* this function uses two pointers to traverse the list; the other
   alternative would be to use one pointer but use it to essentially look
   one node ahead at the next node */
static int insert(Node **head, int value) {
  Node *curr, *prev= NULL, *new_item= NULL;
  int result= 0;

  if (head != NULL) {
    curr= *head;

    /* find first node in list that's greater than or equal to the one we
       want to insert */
    while (curr != NULL && curr->data < value) {
      prev= curr;
      curr= curr->next;
    }

    /* create new node and if memory allocation succeeded fill in its
       fields */
    new_item= malloc(sizeof(*new_item));  /* note this paradigm */
    if (new_item != NULL) {
      new_item->data= value;
      new_item->next= curr;

      if (prev == NULL)
        *head= new_item;  /* special case- inserting new first element */
      else prev->next= new_item;  /* general case- inserting elsewhere */

      result= 1;
    }
  }

  return result;
}

static int delete(Node **head, int value) {
  Node *prev= NULL, *curr;
  int result= 0;

  if (head != NULL) {

    curr= *head;

    while (curr != NULL && curr->data != value) {
      prev= curr;
      curr= curr->next;
    }

    if (curr != NULL) {  /* curr will be NULL if value was not found */
      if (prev == NULL)
        *head= curr->next;
      else prev->next= curr->next;

      free(curr);

      result= 1;
    }

  }

  return result;
}

int main(void) {
  Node *head= NULL;

  insert(&head, 20);
  insert(&head, 30);
  insert(&head, 10);
  insert(&head, 50);

  /*
  printf("%d\n", find(head, 30));
  printf("%d\n", find(head, 40));
  */

  delete(&head, 30);

  return 0;
}
