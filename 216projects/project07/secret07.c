#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

/* CMSC 216, Spring 2023, Project #7
 * Secret test 7 (secret07.c)
 *
 * Tests calling some of the functions on an empty graph.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  String_graph graph;

  graph_init(&graph);

  /* yes, there really is such a thing as a Venezuelan poodle moth!  but
     there is no vertex with that name in the graph */
  assert(isa_vertex(&graph, "Venezuelan poodle moth") == 0);
  assert(vertex_count(&graph) == 0);
  assert(get_graph_edge_weight(&graph, "porcupine", "elephant") == -1);
  assert(neighbor_count(&graph, "caterpillar") == -1);

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
