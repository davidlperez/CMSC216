#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

/* CMSC 216, Spring 2023, Project #7
 * Public test 6 (public06.c)
 *
 * Tests the return value of create_graph_edge() with both positive and
 * negative weight edges.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  String_graph graph;
  char *vertex_names[]= {"hedgehog", "koala", "panda", "kangaroo",
                         "parrot", "giraffe"};
  int i;

  graph_init(&graph);

  /* add some vertices */
  for (i= 0; i < NUM_ELTS(vertex_names); i++)
    add_vertex_to_graph(&graph, vertex_names[i]);

  /* call create_graph_edge() and don't even test for the presence or
     absence of the edges later, just test create_graph_edge()'s return
     value */

  /* these two edges are valid */
  assert(create_graph_edge(&graph, "hedgehog", "kangaroo", 8));
  assert(create_graph_edge(&graph, "koala", "parrot", 2));

  /* this edges is not valid */
  assert(create_graph_edge(&graph, "giraffe", "panda", -10) == 0);

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
