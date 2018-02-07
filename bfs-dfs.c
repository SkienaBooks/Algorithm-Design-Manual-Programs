
/*	bfs-dfs.c
	A generic implementation of graph traversal: breadth-first
	and depth-first search

	begun: March 27, 2002
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
#include "bfs-dfs.h"
#include "bool.h"
#include "queue.h"

bool processed[MAXV+1];	/* which vertices have been processed */
bool discovered[MAXV+1];  /* which vertices have been found */
int parent[MAXV+1];	/* discovery relation */

int entry_time[MAXV+1];         /* time of vertex entry */
int exit_time[MAXV+1];          /* time of vertex exit */
int time;                       /* current event time */

bool finished = FALSE;	/* if true, cut off search immediately */

void initialize_search(graph *g)
{
        int i;                          /* counter */

	time = 0;

        for (i=0; i<=g->nvertices; i++) {
                processed[i] = discovered[i] = FALSE;
                parent[i] = -1;
        }
}

void bfs(graph *g, int start)
{
	queue q;			/* queue of vertices to visit */
	int v;				/* current vertex */
	int y;				/* successor vertex */
	edgenode *p;			/* temporary pointer */

	init_queue(&q);
	enqueue(&q,start);
	discovered[start] = TRUE;

	while (empty_queue(&q) == FALSE) {
		v = dequeue(&q);
		process_vertex_early(v);
		processed[v] = TRUE;
		p = g->edges[v];
		while (p != NULL) {
		    y = p->y;
		    if ((processed[y] == FALSE) || g->directed)
			process_edge(v,y);
		    if (discovered[y] == FALSE) {
			enqueue(&q,y);
			discovered[y] = TRUE;
			parent[y] = v;
		    }
		    p = p->next;
		}
		process_vertex_late(v);
	}
}


int edge_classification(int x, int y)
{
        if (parent[y] == x) return(TREE);
        if (discovered[y] && !processed[y]) return(BACK);
        if (processed[y] && (entry_time[y]>entry_time[x])) return(FORWARD);
        if (processed[y] && (entry_time[y]<entry_time[x])) return(CROSS);

        printf("Warning: self loop (%d,%d)\n",x,y);
        return -1;
}

void dfs(graph *g, int v)
{
	edgenode *p;			/* temporary pointer */
	int y;				/* successor vertex */

	if (finished) return;		/* allow for search termination */

	discovered[v] = TRUE;
        time = time + 1;
        entry_time[v] = time;
        /*printf("entered vertex %d at time %d\n",v, entry_time[v]);*/

	process_vertex_early(v);

	p = g->edges[v];
	while (p != NULL) {
		y = p->y;
		if (discovered[y] == FALSE) {
			parent[y] = v;
			process_edge(v,y);
			dfs(g,y);
		} 
		else if ((!processed[y]) || (g->directed))
			process_edge(v,y);

		if (finished) return;

		p = p->next;
	}

	process_vertex_late(v);

        time = time + 1;
        exit_time[v] = time;
        /*printf("exit vertex %d at time %d\n",v, exit_time[v]);*/

	processed[v] = TRUE;
}


void find_path(int start, int end, int parents[])
{
	if ((start == end) || (end == -1))
		printf("\n%d",start);
	else {
		find_path(start,parents[end],parents);
		printf(" %d",end);
	}
}
