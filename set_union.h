
/*	set_union.h

	Header file for union-find data structure implementation

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

#include "bool.h"

#define SET_SIZE 1000

/* [[[ set_union_cut */
typedef struct {
    int p[SET_SIZE+1];      /* parent element */
    int size[SET_SIZE+1];   /* number of elements in subtree i */
    int n;                  /* number of elements in set */
} set_union;
/* ]]] */

void set_union_init(set_union *s, int n);
void union_sets(set_union *s, int s1, int s2);
bool same_component(set_union *s, int s1, int s2);
void print_set_union(set_union *s);
