/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

/* DO NOT MODIFY THIS FILE OR YOUR CODE WILL NOT COMPILE ON THE SUBMIT
   SERVER */

#include "string-graph-datastructure.h"

void graph_init(String_graph *const graph);
short add_vertex_to_graph(String_graph *const graph, const char new_vertex[]);
short vertex_count(const String_graph *const graph);
short isa_vertex(const String_graph *const graph, const char name[]);
char **get_vertex_list(const String_graph *const graph);
short create_graph_edge(String_graph *const graph, const char source[],
                        const char dest[], int weight);
short get_graph_edge_weight(const String_graph *const graph,
                            const char source[], const char dest[]);
short neighbor_count(const String_graph *const graph, const char vertex[]);

/* in the scope where an array is declared (and *only* in the scope where
 * it's declared), this expression will evaluate to the number of elements
 * in the array
 */
#define NUM_ELTS(arr) ((int) (sizeof(arr) / sizeof(arr[0])))
