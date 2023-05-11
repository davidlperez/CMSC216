#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

/* CMSC 216, Spring 2023, Project #7
 * Public test 8 (public08.c)
 *
 * Tests calling add_vertex_to_graph() with a NULL vertex name.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  String_graph graph;

  graph_init(&graph);

  /* add some vertices, but the fourth one has a NULL name */
  add_vertex_to_graph(&graph, "hedgehog");
  add_vertex_to_graph(&graph, "koala");
  add_vertex_to_graph(&graph, "panda");
  /* should have no effect, but not crash */
  add_vertex_to_graph(&graph, NULL);
  add_vertex_to_graph(&graph, "parrot");
  add_vertex_to_graph(&graph, "giraffe");

  /* test that all of the other add_vertex_to_graph() calls worked fine, and
     the fourth one was just ignored and had no effect */
  assert(vertex_count(&graph) == 5);
  assert(isa_vertex(&graph, "hedgehog"));
  assert(isa_vertex(&graph, "koala"));
  assert(isa_vertex(&graph, "panda"));
  assert(isa_vertex(&graph, "parrot"));
  assert(isa_vertex(&graph, "giraffe"));

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
