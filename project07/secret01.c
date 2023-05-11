#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "string-graph.h"

/* CMSC 216, Spring 2023, Project #7
 * Secret test 1 (secret01.c)
 *
 * Tests that add_vertex_to_graph() is making a copy of vertex names and not
 * just doing pointer aliasing.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  String_graph graph;
  char vertex_name[20];
  char *vertices_to_add[]= {"koala", "parrot", "panda", "salamander",
                            "giraffe", "frog", "dog", "hedgehog"};
  int i;

  graph_init(&graph);

  /* add vertices; note the string vertex_name is overwritten each time */
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++) {
    strcpy(vertex_name, vertices_to_add[i]);
    add_vertex_to_graph(&graph, vertex_name);
  }

  /* now check the vertices */
  assert(vertex_count(&graph) == 8);
  for (i= 0; i < NUM_ELTS(vertices_to_add); i++) {
    strcpy(vertex_name, vertices_to_add[i]);
    assert(isa_vertex(&graph, vertex_name));
  }

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
