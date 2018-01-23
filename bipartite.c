
/*	bipartite.c
	Two color a bipartite graph

	by: Steven Skiena
	begun: March 27, 2002
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

extern bool processed[];	/* which vertices have been processed */
extern bool discovered[];	/* which vertices have been found */
extern int parent[];		/* discovery relation */

extern int entry_time[MAXV+1];	/* time of vertex entry */
extern int exit_time[MAXV+1];	/* time of vertex exit */

#define UNCOLORED	0	/* vertex not yet colored */
#define WHITE		1	/* white vertex */
#define BLACK		2	/* black vertex */

int color[MAXV+1];		/* assigned color of v */
bool bipartite;			/* is the graph bipartite? */

process_vertex_early(int v)
{
}

process_vertex_late(int v)
{
}



process_edge(int x, int y)
{
	if (color[x] == color[y]) {
		bipartite = FALSE;
		printf("Warning: graph not bipartite, due to (%d,%d)\n",x,y);
	}	

	color[y] = complement(color[x]);
}


complement(int color)
{
	if (color == WHITE) return(BLACK);
	if (color == BLACK) return(WHITE);
	
	return(UNCOLORED);
}

twocolor(graph *g)
{
	int i;				/* counter */

	for (i=1; i<=(g->nvertices); i++) 
		color[i] = UNCOLORED;

	bipartite = TRUE;
 
	initialize_search(&g);

	for (i=1; i<=(g->nvertices); i++)
		if (discovered[i] == FALSE) {
			color[i] = WHITE;
			bfs(g,i);
		}
}


main()
{
	graph g;
	int i;

	read_graph(&g,FALSE);
	print_graph(&g);

	twocolor(&g);

	for (i=1; i<=(g.nvertices); i++)
		printf(" %d",color[i]);
	printf("\n");
}
