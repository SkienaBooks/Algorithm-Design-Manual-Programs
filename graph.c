
/*	graph.c         

	A generic adjacency list graph data type.

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

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "graph.h"

void initialize_graph(graph *g, bool directed)
{
	int i;				/* counter */

	g -> nvertices = 0;
	g -> nedges = 0;
	g -> directed = directed;

	for (i=1; i<=MAXV; i++) g->degree[i] = 0;
	for (i=1; i<=MAXV; i++) g->edges[i] = _NULL;
}


void insert_edge(graph *g, int x, int y, bool directed)
{
	edgenode *p;			/* temporary pointer */

	p = malloc(sizeof(edgenode));	/* allocate storage for edgenode */

	p->weight = _NULL;
	p->y = y;
	p->next = g->edges[x];

	g->edges[x] = p;		/* insert at head of list */

	g->degree[x] ++;

	if (directed == FALSE)
		insert_edge(g,y,x,TRUE);
	else
		g->nedges ++;
}


void read_graph(graph *g, bool directed)
{
	int i;				/* counter */
	int m;				/* number of edges */
	int x, y;			/* vertices in edge (x,y) */

	initialize_graph(g, directed);

	scanf("%d %d",&(g->nvertices),&m);

	for (i=1; i<=m; i++) {
		scanf("%d %d",&x,&y);
		insert_edge(g,x,y,directed);
	}
}


void delete_edge(graph *g, int x, int y, bool directed)
{
	int i;				/* counter */
	edgenode *p, *p_back;		/* temporary pointers */

	p = g->edges[x];
	p_back = _NULL;

	while (p != _NULL) 
		if (p->y == y) {
			g->degree[x] --;
			if (p_back != _NULL) 
				p_back->next = p->next;
			else
				g->edges[x] = p->next;

			free(p);

			if (directed == FALSE)
				delete_edge(g,y,x,TRUE);
			else
				g->nedges --;

			return;
		}
		else
			p = p->next;

	printf("Warning: deletion(%d,%d) not found in g.\n",x,y);
}

void print_graph(graph *g)
{
	int i;				/* counter */
	edgenode *p;			/* temporary pointer */

	for (i=1; i<=g->nvertices; i++) {
		printf("%d: ",i);
		p = g->edges[i];
		while (p != _NULL) {
			printf(" %d",p->y);
			p = p->next;
		}
		printf("\n");
	}
}

