
/*	findcycle.c

	Identify a cycle in a graph, if one exists.

	begun: March 6, 2002
	by: Steven Skiena
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

extern bool processed[];    /* which vertices have been processed */
extern bool discovered[];   /* which vertices have been found */
extern int parent[];        /* discovery relation */

extern bool finished;       /* flag for early search cutoff */

void process_vertex_early(int v) {

}

void process_vertex_late(int v) {

}

/* [[[ cyclepedge_cut */
void process_edge(int x, int y) {
    if (parent[x] != y) {    /* found back edge! */
        printf("Cycle from %d to %d:", y, x);
        find_path(y, x, parent);
        printf("\n\n");
        finished = TRUE;
    }
}
/* ]]] */

int main(void) {
    graph g;
    int i;

    read_graph(&g, FALSE);
    print_graph(&g);

    initialize_search(&g);
    dfs(&g, 1);

    return 0;
}
