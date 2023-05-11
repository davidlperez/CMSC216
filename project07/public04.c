#include <stdio.h>
#include <assert.h>
#include "string-graph.h"
#include "compare-vertex-lists.h"

/* CMSC 216, Spring 2023, Project #7
 * Public test 4 (public04.c)
 *
 * Tests calling get_vertex_list() on a graph that has some vertices.
 *
 * (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  String_graph graph;
  char *vertex_names[]= {"elephant", "hedgehog", "kangaroo", "koala",
                         "naked mole rat", "parrot", NULL};
  int i;

  graph_init(&graph);

  /* add some vertices, but don't try to add the last element in the array
     as a vertex name (NULL), hence the "- 1" */
  for (i= 0; i < NUM_ELTS(vertex_names) - 1; i++)
    add_vertex_to_graph(&graph, vertex_names[i]);

  /* use the helper function to ensure that the list of names returned by
     get_vertex_list() equals the expected list declared above */
  assert(compare_vertex_lists(get_vertex_list(&graph), vertex_names));

  printf("I was sure that the assertions would all succeed!\n");

  return 0;
}
