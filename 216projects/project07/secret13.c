#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

/* CMSC 216, Spring 2023, Project #7
 * Secret test 13 (secret13.c)
 *
 * Tests that edges are being properly added- adds edges in both directions
 * between two vertices, adds different outgoing edges with the same weight
 * going from a vertex to different neighbors, and checks that adding an
 * outgoing edge from a vertex does not cause an incoming edge to be added
 * as well.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  String_graph graph;
  char *vertices_to_add[]= {"hedgehog", "koala", "panda", "kangaroo",
                            "parrot", "numbat"};
  int expected_neighbors[]= {3, 0, 1, 1, 0, 0};
  int i;

  graph_init(&graph);

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    add_vertex_to_graph(&graph, vertices_to_add[i]);

  /* add a pair of edges in both directions between two vertices */
  create_graph_edge(&graph, "hedgehog", "kangaroo", 8);
  create_graph_edge(&graph, "kangaroo", "hedgehog", 2);

  /* add multiple outgoing edges from the same vertex with the same weight */
  create_graph_edge(&graph, "hedgehog", "panda", 8);
  create_graph_edge(&graph, "hedgehog", "numbat", 8);

  /* used to check that adding an edge does not add the symmetric edge */
  create_graph_edge(&graph, "panda", "koala", 7);

  /* check the results */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    assert(neighbor_count(&graph, vertices_to_add[i]) ==
           expected_neighbors[i]);

  assert(get_graph_edge_weight(&graph, "hedgehog", "kangaroo") == 8);
  assert(get_graph_edge_weight(&graph, "kangaroo", "hedgehog") == 2);

  assert(get_graph_edge_weight(&graph, "hedgehog", "panda") == 8);
  assert(get_graph_edge_weight(&graph, "hedgehog", "numbat") == 8);

  assert(get_graph_edge_weight(&graph, "koala", "panda") == -1);

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
