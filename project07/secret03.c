#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

/* CMSC 216, Spring 2023, Project #7
 * Secret test 3 (secret03.c)
 *
 * Creates a graph with a large number of vertices.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define NUM_VERTICES 12345

int main(void) {
  String_graph graph;
  char name[12];
  int i;

  graph_init(&graph);

  /* create many vertices */
  for (i= 0; i < NUM_VERTICES; i++) {
    sprintf(name, "vertex%05d", i);
    add_vertex_to_graph(&graph, name);
  }

  assert(vertex_count(&graph) == NUM_VERTICES);

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
