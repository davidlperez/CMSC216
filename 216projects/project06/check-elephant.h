/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else. */

/* DO NOT MODIFY THIS FILE OR YOUR CODE WILL NOT COMPILE ON THE SUBMIT
   SERVER */

/* returns 0 if el_ptr is NULL, and returns 1 if el_ptr is non-NULL but its
 * name is NULL, as long as all the other fields agree with the parameters,
 * including the parameter name being NULL also
 */
unsigned short check_elephant(const Elephant *el_ptr, const char name[],
                              enum type which_type, unsigned int id,
                              unsigned short weight, float trunk_length);
