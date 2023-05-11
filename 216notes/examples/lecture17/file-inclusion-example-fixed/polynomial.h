#if !defined(POLYNOMIAL_H)
#define POLYNOMIAL_H

#include "term.h"

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

typedef struct polynomial {
  int some_made_up_field;
  /* probably other fields are here also */
} Polynomial;

void add_term(Polynomial *p, Term t);
/* other prototypes here */

#endif
