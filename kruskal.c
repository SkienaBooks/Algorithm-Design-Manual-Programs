
/*	kruskal.c

	Compute minimum spanning trees of graphs via Kruskal's algorithm.

	by: Steven Skiena
	begun: March 6, 2002
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


#include <stdlib.h>
#include "bool.h"
#include "graph.h"
#include "set_union.h"

#define MAXINT	100007

typedef struct {
        int x, y;                       /* adjacency info */
        int weight;                     /* edge weight, if any */
} edge_pair;


/************************************************************/


to_edge_array(graph *g, edge_pair e[])
{
	int i,m;			/* counters */
	edgenode *p;			/* temporary pointer */

	m = 0;
        for (i=1; i<=g->nvertices; i++) {
                p = g->edges[i];
                while (p != NULL) {
                        if (p->y > i) {
				e[m].x = i;
				e[m].y = p->y;
				e[m].weight = p->weight;
				m = m+1;
			}
                        p = p->next;
                }
        }
}


bool weight_compare(edge_pair *x, edge_pair *y)
{
	if (x->weight < y->weight) return(-1);
	if (x->weight > y->weight) return(1);
	return(0);
}


kruskal(graph *g)
{
	int i;				/* counter */
	set_union s;			/* set union data structure */
	edge_pair e[MAXV+1];		/* array of edges data structure */
	bool weight_compare();

	set_union_init(&s, g->nvertices);

printf("initialized set union\n");
	to_edge_array(g, e);
	qsort(&e,g->nedges,sizeof(edge_pair),weight_compare);

	for (i=0; i<(g->nedges); i++) {
		print_set_union(&s);
		if (!same_component(s,e[i].x,e[i].y)) {
			printf("edge (%d,%d) of weight %d in MST\n",e[i].x,e[i].y,e[i].weight);
			union_sets(&s,e[i].x,e[i].y);
		}
	}
}

main()
{
	graph g;

	read_graph(&g,FALSE);

	print_graph(&g);

	kruskal(&g);

printf("Out of Kruskal\n");


}

