#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

/* CMSC 216, Spring 2023, Project #7
 * Public test 3 (public03.c)
 *
 * Tests the return value of add_vertex_to_graph() when a new vertex is
 * successfully added, and when it's called on already-existing vertices.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  String_graph graph;
  char *vertex_names[]= {"koala", "parrot", "panda"};
  int i;

  graph_init(&graph);

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertex_names); i++)
    assert(add_vertex_to_graph(&graph, vertex_names[i]));

  /* now try to add them again */
  for (i= 0; i < NUM_ELTS(vertex_names); i++)
    assert(!add_vertex_to_graph(&graph, vertex_names[i]));

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
