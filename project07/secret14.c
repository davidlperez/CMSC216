#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

/* CMSC 216, Spring 2023, Project #7
 * Secret test 14 (secret14.c)
 *
 * Tests that create_graph_edge() does allow zero-weight edges.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  String_graph graph;

  graph_init(&graph);

  add_vertex_to_graph(&graph, "hedgehog");
  add_vertex_to_graph(&graph, "koala");
  add_vertex_to_graph(&graph, "panda");
  add_vertex_to_graph(&graph, "kangaroo");
  add_vertex_to_graph(&graph, "parrot");
  add_vertex_to_graph(&graph, "numbat");

  create_graph_edge(&graph, "hedgehog", "parrot", 1);
  create_graph_edge(&graph, "panda", "koala", 7);

  assert(create_graph_edge(&graph, "hedgehog", "kangaroo", 0) == 1);
  assert(create_graph_edge(&graph, "numbat", "panda", 0) == 1);

  assert(get_graph_edge_weight(&graph, "hedgehog", "kangaroo") == 0);
  assert(get_graph_edge_weight(&graph, "numbat", "panda") == 0);

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
