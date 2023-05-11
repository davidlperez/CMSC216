#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

/* CMSC 216, Spring 2023, Project #7
 * Secret test 8 (secret08.c)
 *
 * Creates a graph with a large number of edges.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define NUM_VERTICES 500

int main(void) {
  String_graph graph;
  char name[11], name2[11];
  int i, j;

  graph_init(&graph);

  /* create many vertices */
  for (i= 0; i < NUM_VERTICES; i++) {
    sprintf(name, "vertex%04d", i);
    add_vertex_to_graph(&graph, name);
  }

  assert(vertex_count(&graph) == NUM_VERTICES);

  /* create many edges; every vertex has an edge to every vertex */
  for (i= 0; i < NUM_VERTICES; i++)
    for (j= 0; j < NUM_VERTICES; j++) {
      sprintf(name, "vertex%04d", i);
      sprintf(name2, "vertex%04d", j);
      assert(create_graph_edge(&graph, name, name2, i + j) == 1);
    }

  /* check the edges */
  for (i= 0; i < NUM_VERTICES; i++) {
    sprintf(name, "vertex%04d", i);
    assert(neighbor_count(&graph, name) == NUM_VERTICES);
  }

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
