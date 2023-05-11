/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* DO NOT MODIFY THIS FILE OR YOUR CODE WILL NOT COMPILE ON THE SUBMIT
 * SERVER. */

enum type {AFRICAN, ASIAN};

typedef struct {
  enum type elephant_type;
  unsigned int id;
  unsigned short weight;
  float trunk_length;
} Elephant;

Elephant new_elephant(enum type which_type, unsigned int id,
                      unsigned short weight, float trunk_length);
unsigned short init_elephant(Elephant *const el_ptr, enum type which_type,
                             unsigned int id, unsigned short weight,
                             float trunk_length);
enum type get_type(Elephant el);
unsigned int get_id(Elephant el);
unsigned short get_weight(Elephant el);
float get_trunk_length(Elephant el);
void print_elephant(Elephant el);
unsigned short compare(Elephant e1, Elephant e2);
unsigned short change_id(Elephant *const el_ptr, unsigned int new_id);
unsigned short copy(Elephant *const el_ptr1, const Elephant *const el_ptr2);
