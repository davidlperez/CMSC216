#include <stdio.h>
#include <assert.h>
#include "string-graph.h"
#include "compare-vertex-lists.h"

/* CMSC 216, Spring 2023, Project #7
 * Secret test 16 (secret16.c)
 *
 * Tests that create_graph_edge() adds vertices that don't already exist.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  String_graph graph;
  char **names;
  char *expected_vertices[]= {"giraffe", "hedgehog", "kangaroo", "koala",
                              "panda", "parrot", NULL};

  graph_init(&graph);

  /* add edges without having added any vertices */
  create_graph_edge(&graph, "hedgehog", "kangaroo", 8);
  create_graph_edge(&graph, "koala", "parrot", 2);
  create_graph_edge(&graph, "giraffe", "panda", 6);
  create_graph_edge(&graph, "koala", "giraffe", 10);
  create_graph_edge(&graph, "hedgehog", "parrot", 1);
  create_graph_edge(&graph, "panda", "koala", 7);
  create_graph_edge(&graph, "hedgehog", "hedgehog", 9);

  /* all the edges should exist */
  assert(get_graph_edge_weight(&graph, "hedgehog", "kangaroo") == 8);
  assert(get_graph_edge_weight(&graph, "koala", "parrot") == 2);
  assert(get_graph_edge_weight(&graph, "giraffe", "panda") == 6);
  assert(get_graph_edge_weight(&graph, "koala", "giraffe") == 10);
  assert(get_graph_edge_weight(&graph, "hedgehog", "parrot") == 1);
  assert(get_graph_edge_weight(&graph, "panda", "koala") == 7);
  assert(get_graph_edge_weight(&graph, "hedgehog", "hedgehog") == 9);

  /* check the vertices also */
  names= get_vertex_list(&graph);
  assert(compare_vertex_lists(names, expected_vertices));

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
