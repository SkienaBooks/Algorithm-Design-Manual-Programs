
/*    topsort1.c

    Topologically sort a directed acyclic graph by DFS numbering (DAG)

    by: Steven Skiena
    begun: March 26, 2002
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

#include "bool.h"
#include "bfs-dfs.h"
#include "stack.h"

stack sorted;    /* topological ordering of vertices */

extern bool processed[];        /* which vertices have been processed */
extern bool discovered[];       /* which vertices have been found */
extern int parent[];            /* discovery relation */

extern int entry_time[];        /* time of vertex entry */
extern int exit_time[];         /* time of vertex exit */


void process_vertex_early(int v) {

}

/* [[[ pvlate_topsort_cut */
void process_vertex_late(int v) {
    push(&sorted, v);
}
/* ]]] */

/* [[[ pedge_topsort_cut */
void process_edge(int x, int y) {
    int class;    /* edge class */

    class = edge_classification(x, y);

    if (class == BACK) {
        printf("Warning: directed cycle found, not a DAG\n");
    }
}
/* ]]] */

/* [[[ topsort_cut */
void topsort(graph *g) {
    int i;    /* counter */

    init_stack(&sorted);

    for (i = 1; i <= g->nvertices; i++) {
        if (discovered[i] == FALSE) {
            dfs(g, i);
        }
    }
    print_stack(&sorted);    /* report topological order */
}
/* ]]] */

int main(void) {
    graph g;

    read_graph(&g, TRUE);
    print_graph(&g);

    topsort(&g);

    return 0;
}
