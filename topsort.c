
/*	topsort.c

	Topologically sort a directed acyclic graph (DAG)

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


#include "bool.h"
#include "graph.h"
#include "queue.h"


compute_indegrees(graph *g, int in[])
{
	int i;				/* counter */
	edgenode *p;			/* temporary pointer */

	for (i=1; i<=g->nvertices; i++) in[i] = 0;

	for (i=1; i<=g->nvertices; i++) {
		p = g->edges[i];
		while (p != NULL) {
			in[ p->y ] ++;
			p = p->next;
		}
	}
}
		

topsort(graph *g, int sorted[])
{
	int indegree[MAXV+1];		/* indegree of each vertex */
	queue zeroin;			/* vertices of indegree 0 */
	int x, y;			/* current and next vertex */
	int i, j;			/* counters */
	edgenode *p;			/* temporary pointer */

	compute_indegrees(g,indegree);
	init_queue(&zeroin);
	for (i=1; i<=g->nvertices; i++)
		if (indegree[i] == 0) enqueue(&zeroin,i);

	j=0;
	while (empty_queue(&zeroin) == FALSE) {
		j = j+1;
		x = dequeue(&zeroin);
		sorted[j] = x;
		p = g->edges[x];
		while (p != NULL) {
			y = p->y;
			indegree[y] --;
			if (indegree[y] == 0) enqueue(&zeroin,y);
			p = p->next;
		}
	}

	if (j != g->nvertices)
		printf("Not a DAG -- only %d vertices found\n",j);
}


main()
{
	graph g;
	int out[MAXV+1];
	int i;

	read_graph(&g,TRUE);
	print_graph(&g);

	topsort(&g,out);

	for (i=1; i<=g.nvertices; i++)
		printf(" %d",out[i]);
	printf("\n");

}

