/*    wgraph.c

    A generic weighted graph data type

    by Steven Skiena
*/


/*
Copyright 2003 by Steven S. Skiena; all rights reserved. 

Permission is granted for use in non-commerical applications
provided this copyright notice remains intact and unchanged.

This program appears in my book:

"Programming Challenges: The Programming Contest Training Manual"
by Steven Skiena and Miguel Revilla, Springer-Verlag, New York 2003.

See our website www.programming-challenges.com for additional information.

This book can be ordered from Amazon.com at

http://www.amazon.com/exec/obidos/ASIN/0387001638/thealgorithmrepo/

*/

#include <stdio.h>
#include <stdlib.h>

#include "bool.h"
#include "graph.h"

void initialize_graph(graph *g, bool directed) {
    int i;    /* counter */

    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;

    for (i = 1; i <= MAXV; i++) {
        g->degree[i] = 0;
    }

    for (i = 1; i <= MAXV; i++) {
        g->edges[i] = NULL;
    }
}

void insert_edge(graph *g, int x, int y, bool directed, int w) {
    edgenode *p;    /* temporary pointer */

    p = malloc(sizeof(edgenode));
    p->y = y;
    p->weight = w;

    p->next = g->edges[x];
    g->edges[x] = p;
    g->degree[x]++;

    if (directed == FALSE) {
        insert_edge(g, y, x, TRUE, w);
    } else {
        g->nedges++;
    }
}

void read_graph(graph *g, bool directed) {
    int i;        /* counter */
    int m;        /* number of edges */
    int x,y,w;    /* placeholder for edge and weight */

    initialize_graph(g,directed);

    scanf("%d %d\n", &(g->nvertices), &m);

    for (i = 1; i <= m; i++) {
        scanf("%d %d %d\n", &x, &y, &w);
        insert_edge(g, x, y, directed, w);
    }
}

void delete_edge(graph *g, int x, int y, bool directed) {
    int i;                          /* counter */
    edgenode *p, *p_back;           /* temporary pointers */

    p = g->edges[x];
    p_back = NULL;

    while (p != NULL) 
        if (p->y == y) {
            g->degree[x]--;
            if (p_back != NULL) {
                p_back->next = p->next;
            } else {
                g->edges[x] = p->next;
            }
            free(p);

            if (directed == FALSE) {
                delete_edge(g, y, x, TRUE);
            } else {
                g->nedges --;
            }
            return;
        } else {
            p = p->next;
        }
        printf("Warning: deletion(%d,%d) not found in g.\n", x, y);
}

void print_graph(graph *g) {
    int i;                          /* counter */
    edgenode *p;                    /* temporary pointer */

    for (i = 1; i <= g->nvertices; i++) {
        printf("%d: ", i);
        p = g->edges[i];
        while (p != NULL) {
            printf(" %d", p->y);
            p = p->next;
        }
        printf("\n");
    }
}

bool processed[MAXV+1];         /* which vertices have been processed */
bool discovered[MAXV+1];        /* which vertices have been found */
int parent[MAXV+1];             /* discovery relation */

int entry_time[MAXV+1];         /* time of vertex entry */
int exit_time[MAXV+1];          /* time of vertex exit */
int time;                       /* current event time */

bool finished = FALSE;          /* if true, cut off search immediately */


void initialize_search(graph *g) {
    int i;    /* counter */

    time = 0;

    for (i = 0; i <= g->nvertices; i++) {
        processed[i] = discovered[i] = FALSE;
        parent[i] = -1;
    }
}

void process_vertex_early(int v) {        /* vertex to process */
    printf(" %d", v);
}

void process_vertex_late(int v) {         /* vertex to process */

}

void process_edge(int x, int y) {         /* edge to process */

}

void dfs(graph *g, int v) {
    edgenode *p;                    /* temporary pointer */
    int y;                          /* successor vertex */

    if (finished) return;           /* allow for search termination */

    discovered[v] = TRUE;
    time = time + 1;
    entry_time[v] = time;

    process_vertex_early(v);

    p = g->edges[v];
    while (p != NULL) {
        y = p->y;
        if (discovered[y] == FALSE) {
            parent[y] = v;
            process_edge(v, y);
            dfs(g, y);
        } else if ((!processed[y]) || (g->directed)) {
            process_edge(v, y);
        }

        if (finished == TRUE) {
            return;
        }

        p = p->next;
    }

    process_vertex_late(v);

    time = time + 1;
    exit_time[v] = time;
    processed[v] = TRUE;
}

void find_path(int start, int end, int parents[]) {
    if ((start == end) || (end == -1)) {
        printf("\n%d", start);
    } else {
        find_path(start, parents[end], parents);
        printf(" %d", end);
    }
}

void connected_components(graph *g) {    /* graph to analyze */
    int c;    /* component number */
    int i;    /* counter */

    initialize_search(g);

    c = 0;
    for (i = 1; i <= g->nvertices; i++) {
        if (discovered[i] == FALSE) {
            c = c + 1;
            printf("Component %d:", c);
            dfs(g, i);
            printf("\n");
        }
    }
}
