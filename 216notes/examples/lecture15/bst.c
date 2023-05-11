#include <stdio.h>
#include <stdlib.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Illustrates a recursive insert() function in C for a binary search tree.
 * Notice specifically the recursive calls, and make sure you understand
 * what's going on.  For practice- write a find() or lookup function and
 * call it from main() to search for some values that are and are not in the
 * tree that is constructed.
 */

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} Node;

static int insert(Node **root, int value);

/* recursive implementation */
int insert(Node **root, int value) {
  Node *new= NULL;
  int result= 0;

  /* avoid crash if an idiotic user passes in NULL */
  if (root != NULL) {

    /* base case where the function's parameter is an empty tree- which
       could be when a node in the tree that just has a NULL pointer */
    if (*root == NULL) {
      new= malloc(sizeof(*new));
 
      /* allocate new node and make its parent point to it */
      if (new != NULL) {
        new->data= value;
        new->left= new->right= NULL;
        *root= new;

        result= 1;
      }

    } else
      /* recursive case- make recursive calls passing into root the memory
         address of either the left or right child pointer of the current
         node */
      if (value < (*root)->data)
        result= insert(&((*root)->left), value);
      else result= insert(&((*root)->right), value);
  }

  return result;
}

int main(void) {
  Node *root= NULL;

  insert(&root, 50);
  insert(&root, 30);
  insert(&root, 20);
  insert(&root, 80);
  insert(&root, 70);
  insert(&root, 90);
  insert(&root, 40);
  insert(&root, 60);

  return 0;
}
