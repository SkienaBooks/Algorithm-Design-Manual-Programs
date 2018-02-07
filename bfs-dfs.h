/*	bfs-dfs.h
	Header file for graph traversal functions

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
#ifndef BFS_DFS_H
#define BFS_DFS_H

#include "graph.h"

void initialize_search(graph *g);
void bfs(graph *g, int start);
int edge_classification(int x, int y);
void dfs(graph *g, int v);
void find_path(int start, int end, int parents[]);

#endif