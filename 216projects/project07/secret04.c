#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

/* CMSC 216, Spring 2023, Project #7
 * Secret test 4 (secret04.c)
 *
 * Creates multiple graphs, to ensure that their data doesn't conflict.  (If
 * your program is using global variables you may fail this test.)
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  String_graph graph1, graph2;
  char *vertices_to_add1[]= {"hedgehog", "koala", "panda"};
  /* yes, there really is such a thing as a Venezuelan poodle moth! */
  char *vertices_to_add2[]= {"orangutan", "jellyfish", "amoeba", "unicorn",
                             "Venezuelan poodle moth"};
  int i;

  graph_init(&graph1);
  graph_init(&graph2);

  /* add some vertices to the first graph */
  for (i= 0; i < NUM_ELTS(vertices_to_add1); i++)
    add_vertex_to_graph(&graph1, vertices_to_add1[i]);

  /* add some vertices to the second graph */
  for (i= 0; i < NUM_ELTS(vertices_to_add2); i++)
    add_vertex_to_graph(&graph2, vertices_to_add2[i]);

  /* add some edges to the first graph */
  create_graph_edge(&graph1, "hedgehog", "koala", 2);
  create_graph_edge(&graph1, "hedgehog", "panda", 3);
  create_graph_edge(&graph1, "koala", "hedgehog", 4);
  create_graph_edge(&graph1, "koala", "panda", 5);
  create_graph_edge(&graph1, "panda", "hedgehog", 6);
  create_graph_edge(&graph1, "panda", "koala", 7);

  /* add some edges to the second graph */
  for (i= 0; i < NUM_ELTS(vertices_to_add2); i++)
    create_graph_edge(&graph2, vertices_to_add2[i],
                      vertices_to_add2[(i + 2) % NUM_ELTS(vertices_to_add2)],
                      i + 2);

  /* check the results */
  for (i= 0; i < NUM_ELTS(vertices_to_add1); i++)
    assert(neighbor_count(&graph1, vertices_to_add1[i]) == 2);

  for (i= 0; i < NUM_ELTS(vertices_to_add2); i++)
    assert(neighbor_count(&graph2, vertices_to_add2[i]) == 1);

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
