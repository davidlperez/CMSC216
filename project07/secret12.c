#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

/* CMSC 216, Spring 2023, Project #7
 * Secret test 12 (secret12.c)
 *
 * Tests that create_graph_edge() does not actually add an edge when the
 * edge has a negative weight.
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

  create_graph_edge(&graph, "hedgehog", "kangaroo", 8);
  create_graph_edge(&graph, "koala", "parrot", 2);
  create_graph_edge(&graph, "numbat", "panda", 6);
  create_graph_edge(&graph, "koala", "numbat", 10);
  create_graph_edge(&graph, "hedgehog", "parrot", 1);
  create_graph_edge(&graph, "panda", "koala", 7);
  create_graph_edge(&graph, "hedgehog", "hedgehog", 9);

  assert(create_graph_edge(&graph, "hedgehog", "parrot", -5) == 0);

  assert(get_graph_edge_weight(&graph, "hedgehog", "parrot") == 1);

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
