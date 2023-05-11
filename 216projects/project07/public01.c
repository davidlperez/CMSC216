#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

/* CMSC 216, Spring 2023, Project #7
 * Public test 1 (public01.c)
 *
 * Tests initializing a graph and calling vertex_count() before any vertices
 * have been added, then after some vertices have been added.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  String_graph graph;
  char *vertex_names[]= {"hedgehog", "koala", "parrot", "kangaroo",
                         "elephant", "naked mole rat"};
  int i;

  graph_init(&graph);

  /* the graph should be completely devoid of vertices */
  assert(vertex_count(&graph) == 0);

  /* let's address that situation now */
  for (i= 0; i < NUM_ELTS(vertex_names); i++)
    add_vertex_to_graph(&graph, vertex_names[i]);

  /* how many vertices now? */
  assert(vertex_count(&graph) == NUM_ELTS(vertex_names));

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
