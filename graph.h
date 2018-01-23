/*	graph.h
	Header file for pointer-based graph data type

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


#define	MAXV		100		/* maximum number of vertices */
#define NULL		0		/* null pointer */

/*	DFS edge types		*/

#define TREE		0		/* tree edge */
#define BACK		1		/* back edge */
#define CROSS		2		/* cross edge */
#define FORWARD		3		/* forward edge */

typedef struct edgenode {
	int y;				/* adjancency info */
	int weight;			/* edge weight, if any */
	struct edgenode *next;		/* next edge in list */
} edgenode;

typedef struct {
	edgenode *edges[MAXV+1];	/* adjacency info */
	int degree[MAXV+1];		/* outdegree of each vertex */
	int nvertices;			/* number of vertices in the graph */
	int nedges;			/* number of edges in the graph */
	int directed;			/* is the graph directed? */
} graph;


