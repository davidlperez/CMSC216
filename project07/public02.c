#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

/* CMSC 216, Spring 2023, Project #7
 * Public test 2 (public02.c)
 *
 * Tests initializing a graph and calling vertex_count() before any vertices
 * have been added, then on some vertices that have been added to the graph,
 * as well as some nonexistent vertices.
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

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertex_names); i++)
    add_vertex_to_graph(&graph, vertex_names[i]);

  /* check that these are existent vertices */
  assert(isa_vertex(&graph, "hedgehog"));
  assert(isa_vertex(&graph, "parrot"));
  assert(isa_vertex(&graph, "elephant"));
  assert(isa_vertex(&graph, "naked mole rat"));

  /* check that these are nonexistent vertices */
  assert(!isa_vertex(&graph, "deer"));
  assert(!isa_vertex(&graph, "rabbit"));

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
