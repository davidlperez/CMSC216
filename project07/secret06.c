#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

/* CMSC 216, Spring 2023, Project #7
 * Secret test 6 (secret06.c)
 *
 * Tests that vertex names are being correctly compared when edges are
 * added, and looked up using get_graph_edge_weight().  This also tests
 * calling create_graph_edge() and get_graph_edge_weight() with nonexistent
 * source and destination vertices.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  String_graph graph;
  char *vertices_to_add[]= {"caterpillar", "porcupine", "elephant"};
  int i, j;

  graph_init(&graph);

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    add_vertex_to_graph(&graph, vertices_to_add[i]);

  /* add some edges */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    for (j= 0; j < NUM_ELTS(vertices_to_add); j++)
      create_graph_edge(&graph, vertices_to_add[i], vertices_to_add[j],
                        (i * 10) + j);

  /* these are not names of existing vertices */
  assert(get_graph_edge_weight(&graph, "Caterpillar", "porcupine") == -1);
  assert(get_graph_edge_weight(&graph, "porcupine", "Caterpillar") == -1);
  assert(get_graph_edge_weight(&graph, "ELEPHANT", "caterpillar") == -1);
  assert(get_graph_edge_weight(&graph, "caterpillar", "ELEPHANT") == -1);
  assert(get_graph_edge_weight(&graph, "cat", "ant") == -1);
  assert(get_graph_edge_weight(&graph, "ant", "cat") == -1);
  assert(get_graph_edge_weight(&graph, "cup", "cat") == -1);
  assert(get_graph_edge_weight(&graph, "cat", "cup") == -1);

  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    for (j= 0; j < NUM_ELTS(vertices_to_add); j++)
      assert(get_graph_edge_weight(&graph, vertices_to_add[i],
                                   vertices_to_add[j]) == (i * 10) + j);

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
