#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

/* CMSC 216, Spring 2023, Project #7
 * Secret test 15 (secret15.c)
 *
 * Tests calling create_graph_edge() to change the weights of some existing
 * edges that are already present in a graph.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  String_graph graph;

  graph_init(&graph);

  /* add vertices */
  add_vertex_to_graph(&graph, "hedgehog");
  add_vertex_to_graph(&graph, "koala");
  add_vertex_to_graph(&graph, "panda");
  add_vertex_to_graph(&graph, "kangaroo");
  add_vertex_to_graph(&graph, "parrot");
  add_vertex_to_graph(&graph, "giraffe");

  /* add edges between them */
  create_graph_edge(&graph, "hedgehog", "kangaroo", 8);
  create_graph_edge(&graph, "koala", "parrot", 2);
  create_graph_edge(&graph, "giraffe", "panda", 6);
  create_graph_edge(&graph, "koala", "giraffe", 10);
  create_graph_edge(&graph, "hedgehog", "parrot", 1);
  create_graph_edge(&graph, "panda", "koala", 7);
  create_graph_edge(&graph, "hedgehog", "hedgehog", 9);

  /* change some of the edge weights; because these edges already exist */
  create_graph_edge(&graph, "koala", "giraffe", 100);
  create_graph_edge(&graph, "panda", "koala", 400);
  create_graph_edge(&graph, "hedgehog", "kangaroo", 200);
  create_graph_edge(&graph, "hedgehog", "hedgehog", 300);
  /* changing the edge weight to be the same as before is also OK */
  create_graph_edge(&graph, "giraffe", "panda", 6);

  /* check the edge weights have changed */
  assert(get_graph_edge_weight(&graph, "koala", "giraffe") == 100);
  assert(get_graph_edge_weight(&graph, "panda", "koala") == 400);
  assert(get_graph_edge_weight(&graph, "hedgehog", "kangaroo") == 200);
  assert(get_graph_edge_weight(&graph, "hedgehog", "hedgehog") == 300);
  assert(get_graph_edge_weight(&graph, "giraffe", "panda") == 6);

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
