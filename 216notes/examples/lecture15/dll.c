#include <stdio.h>
#include <stdlib.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* dll.c == "doubly-linked-list.c"
 * Illustrates doubly-linked list insertion in C (compare to Java).  For
 * practice- write a delete() function, and write code to print the values
 * stored in the list at the end of main(), or even better, as a lookup or
 * search or find function to be called upon the head node.
 */

typedef struct node {
  struct node *next;
  struct node *prev;
  int data;
} Node;

static int insert(Node **head, Node **tail, int value);

/* This function works, but we can write it better.  An improved version
   will be shown soon. */
int insert(Node **head, Node **tail, int value) {
  Node *curr, *new_node= NULL;
  int result= 0;

  if (head != NULL && tail != NULL) {
    curr= *head;

    /* because this is a doubly linked list we can traverse with just one
       pointer, because even though we find the node one past where we need
       to insert the new value, we can look back and modify the node before
       it */
    while (curr != NULL && curr->data <= value)
      curr= curr->next;

    new_node= malloc(sizeof(*new_node));  /* note this paradigm */
    if (new_node != NULL) {
      result= 1;
      new_node->data= value;

      if (*head == NULL) {     /* case 1: empty list case */
        *head= new_node;
        *tail= new_node;
        new_node->next= NULL;
        new_node->prev= NULL;

      } else
        if (curr == *head) {   /* case 2: beginning of list case */
          new_node->prev= NULL;
          new_node->next= *head;
          curr->prev= new_node;
          *head= new_node;

        } else
          if (curr == NULL) {  /* case 3: end of list case */
            new_node->prev= *tail;
            (*tail)->next= new_node;
            new_node->next= curr;
            *tail= new_node;

          } else {             /* case 4: general (middle of list) case */
            new_node->prev= curr->prev;
            new_node->next= curr;
            curr->prev->next= new_node;
            curr->prev= new_node;

          }
    }
  }

  return result;
}

int main(void) {
  Node *head= NULL, *tail= NULL;

  insert(&head, &tail, 20);
  insert(&head, &tail, 30);
  insert(&head, &tail, 10);
  insert(&head, &tail, 50);

  /* exercise- write code to print the values stored in the list here, or
     even better, as a function to be called upon the head node */

  return 0;
}
