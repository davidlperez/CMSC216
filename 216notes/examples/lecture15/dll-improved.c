#include <stdio.h>
#include <stdlib.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Improved doubly-linked list (ordered, with a head and a tail pointer)
   insert() function. */

typedef struct node {
  struct node *next;
  struct node *prev;
  int data;
} Node;

static int insert(Node **head, Node **tail, int value);

int insert(Node **head, Node **tail, int value) {
  Node *new_node, *curr;
  int result= 0;

  if (head != NULL) {

    curr= *head;
    while (curr != NULL && curr->data <= value)
      curr= curr->next;

    new_node= malloc(sizeof(*new_node));
    if (new_node != NULL) {

      result= 1;
      new_node->data= value;
      new_node->next= curr;    /* do this in all four cases */

      if (curr == NULL) {  /* if list empty or at end; test for cases 1 or 3 */

        new_node->prev= *tail;                               
        if (*head == NULL)                /* insert into empty list */
          *head= new_node;                /* case 1 */
        else (*tail)->next= new_node;     /* case 3 */
        *tail= new_node;       /* must be after (*tail)->next is used above */

      } else {                 /* otherwise this must be case 2 or 4 */

        new_node->prev= curr->prev;                            
        if (curr == *head)                /* insert as new first item */
          *head= new_node;                /* case 2 */
        else curr->prev->next= new_node;  /* case 4 */
        curr->prev= new_node;  /* must be after curr->prev->next used above */
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
