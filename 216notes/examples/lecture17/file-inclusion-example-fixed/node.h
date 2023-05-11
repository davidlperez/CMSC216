#if !defined(NODE_H)
#define NODE_H

#include "term.h"

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

typedef struct node {
  Term term;
  struct node *next;
} Node;

/* some prototypes here */

#endif
