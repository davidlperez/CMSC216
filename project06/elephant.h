/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* DO NOT MODIFY THIS FILE OR YOUR CODE WILL NOT COMPILE ON THE SUBMIT
 * SERVER. */

enum type {AFRICAN, ASIAN};

typedef struct {
  char *name;
  enum type elephant_type;
  unsigned int id;
  unsigned short weight;
  float trunk_length;
} Elephant;

Elephant *new_elephant(const char name[], enum type which_type,
                       unsigned int id, unsigned short weight,
                       float trunk_length);
unsigned short get_type(const Elephant *const el_ptr,
                        enum type *const type_ptr);
const char *get_name(const Elephant *const el_ptr);
void print_elephant(const Elephant *const el_ptr);
short compare(const Elephant *const el_ptr1, const Elephant *const el_ptr2);
unsigned short change_name(Elephant *const el_ptr, const char new_name[]);
unsigned short copy(Elephant *const el_ptr1, const Elephant *const el_ptr2);
