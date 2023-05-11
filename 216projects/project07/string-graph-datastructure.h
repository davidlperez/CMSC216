/* David Perez
 * dperez7
 * 117915402
 * CMSC216 (0107) Project 7 string-graph-datastructure.h */

/* This header file proveds the 3 structs used in the graph implentation using a
 * linked list. */

/* This struct represents a vertex in the graph. It contains a pointer to the
 * first edge in the linked list of edges, a pointer to the next vertex in the
 * linked list of vertices, and a pointer to the name of the vertex. */
typedef struct Vertex {
    char *name;
    struct Edge *edges;
    struct Vertex *next;
} Vertex;

/* This struct represents an edge in the graph. It contains a pointer to the
 * destination vertex, a pointer to the next edge in the linked list of edges,
 * and an integer representing the weight of the edge. */
typedef struct Edge {
    int weight;
    struct Vertex *destination;
    struct Edge *next;
} Edge;

/* This struct represents the graph. It contains a pointer to the first vertex
 * in the linked list of vertices and an integer representing the number of
 * vertices in the graph. */
typedef struct Graph {
    int num_vertices;
    struct Vertex *head;
} String_graph;
