#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

/* CMSC 216, Spring 2023, Project #7
 * Secret test 10 (secret10.c)
 *
 * Tests calling neighbor_count() on a nonexistent vertex.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  String_graph graph;
  char *vertices_to_add[]= {"caterpillar", "porcupine", "elephant"};
  int i;

  graph_init(&graph);

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    add_vertex_to_graph(&graph, vertices_to_add[i]);

  assert(neighbor_count(&graph, "Venezuelan poodle moth") == -1);

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
