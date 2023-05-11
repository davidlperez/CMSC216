#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

/* CMSC 216, Spring 2023, Project #7
 * Secret test 2 (secret02.c)
 *
 * Tests that vertex names are being correctly compared when vertices are
 * added and looked up using isa_vertex().
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

  /* these are not names of existing vertices */
  assert(isa_vertex(&graph, "Caterpillar") == 0);
  assert(isa_vertex(&graph, "ELEPHANT") == 0);
  assert(isa_vertex(&graph, "cat") == 0);
  assert(isa_vertex(&graph, "cup") == 0);
  assert(isa_vertex(&graph, "ant") == 0);

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
