/* David Perez
 * dperez7
 * 117915402
 * CMSC216 (0107) Project 8 string-graph.c */

#include "string-graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This function initializes an empty graph
 */
void graph_init(String_graph *const graph) {
    if (graph != NULL) {
        graph->head = NULL;
        graph->num_vertices = 0;
    }
}

/*
 * This function checks takes a string parameter and adds it to the
 * string graph as a vertex.
 */
short add_vertex_to_graph(String_graph *const graph, const char new_vertex[]) {
    Vertex *new_vertex_ptr;
    Vertex *curr_vertex;
    char *new_name;

    /*
     * Checks if either of the parameters are NULL. Does nothing and returns
     * 0 if it is.
     */
    if (graph == NULL || new_vertex == NULL) {
        return 0;
    }
    curr_vertex = graph->head;

    /* Checks if vertex already exists in graph and returns 0 if it does */
    while (curr_vertex != NULL) {
        if (strcmp(curr_vertex->name, new_vertex) == 0) {
            return 0;
        }
        curr_vertex = curr_vertex->next;
    }

    /* Creates a new vertex and adds it to the graph */
    new_vertex_ptr = malloc(sizeof(Vertex));

    if (new_vertex_ptr == NULL) {
        return 0;
    }

    /* Allocates the memory needed to set the name field of the new vertex to
     * the input string */
    new_vertex_ptr->name = malloc((strlen(new_vertex) + 1) * sizeof(char));
    if (new_vertex_ptr->name == NULL) { /* checks if memory allocate success */
        free(new_vertex_ptr);
        return 0;
    }

    /* Copeies the name of the new vertex into a newly-allocated array */
    new_name = malloc(strlen(new_vertex) + 1);

    /* Checks if memory allocation was successful */
    if (new_name == NULL) {
        free(new_vertex_ptr->name);
        free(new_vertex_ptr);
        return 0;
    }
    /* Copies the name of the new vertex into the newly-allocated array */
    strcpy(new_name, new_vertex);
    strcpy(new_vertex_ptr->name, new_name);
    free(new_vertex_ptr->name);
    new_vertex_ptr->name = new_name;
    new_vertex_ptr->edges = NULL;
    new_vertex_ptr->next = graph->head;
    graph->head = new_vertex_ptr;
    graph->num_vertices++;

    return 1;
}

/*
 * Returns the amount of vertices in the string graph
 */
short vertex_count(const String_graph *const graph) {
    return graph->num_vertices;
}

/*
 * Iterates through the graph and returns 1 if a vertex exists with the same
 * name and 0 otherwise.
 */
short isa_vertex(const String_graph *const graph, const char name[]) {
    Vertex *curr_vertex = graph->head;

    while (curr_vertex != NULL) {
        if (strcmp(curr_vertex->name, name) == 0) {
            return 1;
        }
        curr_vertex = curr_vertex->next;
    }
    return 0;
}

char **get_vertex_list(const String_graph *const graph) {
    int i = 0, j, k;
    char **vertex_names;
    Vertex *curr_vertex;
    char *temp;

    if (graph == NULL) {
        return NULL;
    }

    curr_vertex = graph->head;
    /* Allocated memory for the vertex_names array */
    vertex_names = malloc(((graph->num_vertices) + 1) * sizeof(char *));
    if (vertex_names == NULL) {
        return NULL;
    }

    /* Marks the end of the array with NULL */
    vertex_names[(graph->num_vertices)] = NULL;

    while (curr_vertex != NULL) {
        /* Allocate memory for each vertex name*/
        vertex_names[i] =
            malloc((strlen(curr_vertex->name) + 1) * sizeof(char));

        /* Copy the vertex name to the array*/
        strcpy(vertex_names[i++], curr_vertex->name);

        curr_vertex = curr_vertex->next;
    }

    /* Sort the vertex names alphabetically */
    for (j = 0; j < i - 1; j++) {
        for (k = j + 1; k < i; k++) {
            if (strcmp(vertex_names[j], vertex_names[k]) > 0) {
                temp = vertex_names[j];
                vertex_names[j] = vertex_names[k];
                vertex_names[k] = temp;
            }
        }
    }

    return vertex_names;
}

/* Adds and edge with a specified weight that connects from a source vertex to a
 * destination vertex */
short create_graph_edge(String_graph *const graph, const char source[],
                        const char dest[], int weight) {
    Vertex *source_vertex = NULL;
    Vertex *dest_vertex = NULL;
    Edge *new_edge = NULL, *curr_edge, *prev_edge = NULL;
    int edge_exists = 0; /* 1 if edge exists, 0 otherwise */

    /* Checks if any of the parameters are NULL */
    if (graph == NULL || weight < 0 || source == NULL || dest == NULL) {
        return 0;
    }

    /* Checks if the source and destination vertices exist in the graph */
    if (isa_vertex(graph, source) == 0) {
        add_vertex_to_graph(graph, source);
    }
    if (isa_vertex(graph, dest) == 0) {
        add_vertex_to_graph(graph, dest);
    }

    /* Finds the source and destination vertices in the graph */
    source_vertex = graph->head;
    while (source_vertex != NULL &&
           (strcmp(source_vertex->name, source) != 0)) {
        source_vertex = source_vertex->next;
    }

    dest_vertex = graph->head;
    while (dest_vertex != NULL && (strcmp(dest_vertex->name, dest) != 0)) {
        dest_vertex = dest_vertex->next;
    }

    curr_edge = source_vertex->edges;

    /* Checks if the edge already exists */
    while (curr_edge != NULL) {
        if (strcmp((curr_edge->destination)->name, dest) == 0) {
            edge_exists = 1;
            curr_edge->weight = weight;
        }
        prev_edge = curr_edge;
        curr_edge = curr_edge->next;
    }

    /* Creates a new edge if it does not exist */
    if (edge_exists == 0) {
        new_edge = malloc(sizeof(struct Edge));
        new_edge->weight = weight;
        new_edge->next = NULL;
    }

    /* Returns 0 if any of the vertices are NULL */
    if (source_vertex == NULL || dest_vertex == NULL) {
        return 0;
    }

    /* Adds the edge to the source vertex */
    if (prev_edge == NULL) {
        source_vertex->edges = new_edge;
    } else {
        prev_edge->next = new_edge;
    }

    new_edge->destination = dest_vertex;

    return 1;
}

/* Returns the associated weight between a source vertex to a destination
 * vertex */
short get_graph_edge_weight(const String_graph *const graph,
                            const char source[], const char dest[]) {
    Vertex *curr_vertex = graph->head;
    Edge *curr_edge;

    /* Returns -1 if any parameter is NULL */
    if (graph == NULL || source == NULL || dest == NULL) {
        return -1;
    }
    /* Iterates through graph and finds vertex that matches source, if it exists
     */
    while (curr_vertex != NULL && strcmp(curr_vertex->name, source) != 0) {
        curr_vertex = curr_vertex->next;
    }

    if (curr_vertex == NULL) {
        return -1; /* vertex source not found */
    }
    curr_edge = curr_vertex->edges;

    /* Iterates through graph and finds vertex that matches dset */
    while (curr_edge != NULL &&
           strcmp((curr_edge->destination)->name, dest) != 0) {
        curr_edge = curr_edge->next;
    }

    if (curr_edge == NULL) {
        return -1; /* edge from source to dest not found */
    }

    return curr_edge->weight;
}

/* Returns the number of outgoing edges a given vertex has */
short neighbor_count(const String_graph *const graph, const char vertex[]) {
    Vertex *curr_vertex = graph->head;
    Edge *curr_edge;
    int count = 0;

    /* Returns -1 if either of the parameters are NULL */
    if (graph == NULL || vertex == NULL) {
        return -1;
    }

    /* Find the vertex in the graph */
    while (curr_vertex != NULL && strcmp(curr_vertex->name, vertex) != 0) {
        curr_vertex = curr_vertex->next;
    }

    /* Check if the vertex was found */
    if (curr_vertex == NULL) {
        return -1; /* vertex source not found */
    }

    /* Count the number of edges */
    curr_edge = curr_vertex->edges;
    while (curr_edge != NULL) {
        count++;
        curr_edge = curr_edge->next;
    }

    return count;
}

/* Frees all dynamically-allocated memory associated with the strings in the
 * array names */
void free_vertex_name_list(char **const names) {
    int i = 0; /* Index of the array */

    /* Does nothing if the array is NULL */
    if (names == NULL) {
        return;
    }

    /* Free each vertex name */
    for (i = 0; names[i] != NULL; i++) {
        free(names[i]);
    }

    /* Free the array */
    free(names);
}

/* Returns an array of strings containing the names of all vertices in the
 * graph */
char **get_neighbor_names(const String_graph *const graph,
                          const char vertex[]) {
    char **new_arr; /* Array to store the vertex names */
    Vertex *curr_vertex;
    Edge *curr_edge;       /* Pointer to the current edge */
    int i = 0, j, k;       /* Indices of the array */
    char *neighbor_name;   /* Temporary variable to store the vertex name */
    int num_neighbors = 0; /* Number of neighbors of the vertex */

    /* Returns NULL if graph is NULL or if vertex does not exist in graph */
    if (graph == NULL || !(isa_vertex(graph, vertex))) {
        return NULL;
    }

    curr_vertex = graph->head;

    /* Iterates through graph and finds vertex that matches vertex */
    while (curr_vertex != NULL && strcmp(curr_vertex->name, vertex) != 0) {
        curr_vertex = curr_vertex->next;
    }

    if (curr_vertex == NULL) {
        return NULL; /* vertex source not found */
    }

    /* Counts the number of neighbors */
    curr_edge = curr_vertex->edges;
    while (curr_edge != NULL) {
        num_neighbors++;
        curr_edge = curr_edge->next;
    }

    /* Allocates memory for new_arr */
    new_arr = malloc((num_neighbors + 1) * sizeof(char *));
    /* Checks success of memory allocation */
    if (new_arr == NULL) {
        return NULL;
    }

    new_arr[num_neighbors] = NULL; /* Sets the last element to NULL */

    curr_edge = curr_vertex->edges;

    /* Iterates through the edges and copies the vertex names into new_arr */
    while (curr_edge != NULL) {
        neighbor_name =
            malloc((strlen(curr_edge->destination->name) + 1) * sizeof(char));
        if (neighbor_name == NULL) {
            /* Frees all memory allocated to new_arr */
            while (i > 0) {
                free(new_arr[i--]);
            }
            free(new_arr); /* Frees the array */
            return NULL;
        }
        strcpy(neighbor_name, curr_edge->destination->name);
        new_arr[i++] = neighbor_name;
        curr_edge = curr_edge->next;
    }

    /* Sorts the array in alphabetical order */
    for (j = 0; j < num_neighbors - 1; j++) {
        for (k = j + 1; k < num_neighbors; k++) {
            if (strcmp(new_arr[j], new_arr[k]) > 0) {
                neighbor_name = new_arr[j];
                new_arr[j] = new_arr[k];
                new_arr[k] = neighbor_name;
            }
        }
    }

    return new_arr;
}

/* Removes an edge from the graph given the source vertex and destination vertex
 * the edge connects */
int remove_graph_edge(String_graph *const graph, const char source[],
                      const char dest[]) {
    Vertex *source_vertex, *dest_vertex; /* Pointers to the source and
                                            destination vertices */
    Edge *curr_edge, *prev_edge;         /* Pointers to the current and previous
                                            edges */
    
    /* Returns 0 if any of the parameters are NULL or if the vertices do not
     * exist in the graph */
    if (graph == NULL || source == NULL || dest == NULL ||
        !isa_vertex(graph, source) || !isa_vertex(graph, dest)) {
        return 0;
    }

    source_vertex = graph->head;
    /* Find the source vertex in the graph */
    while (source_vertex != NULL && strcmp(source_vertex->name, source) != 0) {
        source_vertex = source_vertex->next;
    }

    if (source_vertex == NULL) {
        return 0; /* vertex source not found */
    }

    dest_vertex = graph->head;
    while (dest_vertex != NULL && strcmp(dest_vertex->name, dest) != 0) {
        dest_vertex = dest_vertex->next;
    }

    if (dest_vertex == NULL) {
        return 0; /* vertex dest not found */
    }

    /* Find the edge from source to dest */
    curr_edge = source_vertex->edges;
    prev_edge = NULL;
    while (curr_edge != NULL &&
           strcmp(curr_edge->destination->name, dest) != 0) {
        prev_edge = curr_edge;
        curr_edge = curr_edge->next;
    }
    if (curr_edge == NULL) {
        return 0; /* edge not found */
    }

    /* Removes the edge from the source vertex */
    if (prev_edge == NULL) {
        source_vertex->edges = curr_edge->next;
    } else {
        prev_edge->next = curr_edge->next;
    }
    free(curr_edge); /* Frees the edge */

    return 1;
}

/* Removes a vertex from the graph given the vertex name */
int remove_vertex_from_graph(String_graph *const graph, const char vertex[]) {
    Vertex *curr_vertex, *prev_vertex, *temp; /* Pointers to the current and
                                          previous vertices */
    Edge *curr_edge, *next_edge; /* Pointers to the current and previous
                                    edges */
    
    /* Returns 0 if any of the parameters are NULL or if the vertex does not
     * exist in the graph */
    if (graph == NULL || vertex == NULL || !isa_vertex(graph, vertex)) {
        return 0;
    }

    curr_vertex = graph->head;
    prev_vertex = NULL;

    while (curr_vertex != NULL && strcmp(curr_vertex->name, vertex) != 0) {
        prev_vertex = curr_vertex;
        curr_vertex = curr_vertex->next;
    }

    if (curr_vertex == NULL) {
        return 0; /* vertex not found */
    }

    temp = graph->head;
    while (temp != NULL) {
        remove_graph_edge(graph, temp->name, vertex);
        temp = temp->next;
    }

    /* Remove vertex from graph */
    curr_edge = curr_vertex->edges;
    while (curr_edge != NULL) {
        next_edge = curr_edge->next;
        free(curr_edge); /* Frees the edge */
        curr_edge = next_edge;
    }

    /* Frees the vertex */
    free(curr_vertex->name);
    
    /* Removes the vertex from the graph */
    if (prev_vertex == NULL) {
        graph->head = curr_vertex->next;
    } else {
        prev_vertex->next = curr_vertex->next;
    }
    free(curr_vertex); /* Frees the vertex */
    graph->num_vertices--; /* Decrements the number of vertices in the graph */

    return 1;
}

/* Frees all memory allocated to the graph */
void graph_delete(String_graph *const graph) {
    Vertex *curr_vertex = graph->head; /* Pointer to the current vertex */
    Edge *curr_edge, *next_edge; /* Pointers to the current and next edges */

    /* Iterates through the vertices and frees all memory allocated to them */
    while (curr_vertex != NULL) {
        curr_edge = curr_vertex->edges;
        
        /* Iterates through the edges and frees all memory allocated to them */
        while (curr_edge != NULL) {
            next_edge = curr_edge->next;
            free(curr_edge);
            curr_edge = next_edge;
        }
        
        free(curr_vertex->name); /* Frees the vertex name */
        curr_vertex = curr_vertex->next;
        free(graph->head); /* Frees the vertex */
        graph->head = curr_vertex;
    }
    graph->num_vertices = 0; /* Sets the number of vertices to 0 */
}