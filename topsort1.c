
/*	topsort1.c

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


#include "bool.h"
#include "graph.h"
#include "stack.h"

stack sorted;			/* topological ordering of vertices */

extern bool processed[];        /* which vertices have been processed */
extern bool discovered[];       /* which vertices have been found */
extern int parent[];            /* discovery relation */

extern int entry_time[];        /* time of vertex entry */
extern int exit_time[];         /* time of vertex exit */


process_vertex_early(int v)
{
}

process_vertex_late(int v)
{
	push(&sorted,v);
}

process_edge(int x, int y)
{
        int class;              /* edge class */

        class = edge_classification(x,y);

	if (class == BACK) 
		printf("Warning: directed cycle found, not a DAG\n");
}



topsort(graph *g)
{
	int i;				/* counter */

	init_stack(&sorted);

        for (i=1; i<=g->nvertices; i++)
                if (discovered[i] == FALSE) 
                        dfs(g,i);

	print_stack(&sorted);		/* report topological order */
}


main()
{
	graph g;

	read_graph(&g,TRUE);
	print_graph(&g);

	topsort(&g);

}

