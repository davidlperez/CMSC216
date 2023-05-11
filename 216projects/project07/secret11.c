#include <stdio.h>
#include <assert.h>
#include "string-graph.h"

/* CMSC 216, Spring 2023, Project #7
 * Secret test 11 (secret11.c)
 *
 * Tests calling some of the functions passing NULL into String_graph
 * pointer parameters.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  String_graph graph;
  char *vertices_to_add[]= {"orangutan", "jellyfish", "amoeba", "unicorn",
                            "Indian purple frog"};
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

  /* pass NULL into all functions that take a pointer to a String_graph as
     an argument */
  assert(add_vertex_to_graph(NULL, "snail") == 0);
  assert(create_graph_edge(NULL, "eel", "jellyfish", 1) == 0);

  /* check that nothing in the graph changed */
  assert(vertex_count(&graph) == 5);

  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    assert(isa_vertex(&graph, vertices_to_add[i]));

  for (i= 0; i < NUM_ELTS(vertices_to_add); i++)
    for (j= 0; j < NUM_ELTS(vertices_to_add); j++)
      assert(get_graph_edge_weight(&graph, vertices_to_add[i],
                                vertices_to_add[j]) == (i * 10) + j);

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
