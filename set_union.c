
/*	set_union.c

	Implementation of a heap / priority queue abstract data type.

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


#include "set_union.h"
#include "bool.h"


set_union_init(set_union *s, int n)
{
	int i;				/* counter */

	for (i=1; i<=n; i++) {
		s->p[i] = i;
		s->size[i] = 1;
	}
	
        s->n = n;
}

int find(set_union *s, int x)
{
	if (s->p[x] == x)
		return(x);
	else
		return( find(s,s->p[x]) );
}

void union_sets(set_union *s, int s1, int s2)
{
	int r1, r2;			/* roots of sets */

	r1 = find(s,s1);
	r2 = find(s,s2);

printf("s1=%d r1=%d s2=%d r2=%d\n",s1,r1,s2,r2);

	if (r1 == r2) return;		/* already in same set */

	if (s->size[r1] >= s->size[r2]) {
		s->size[r1] = s->size[r1] + s->size[r2];
		s->p[ r2 ] = r1;
	}
	else {
		s->size[r2] = s->size[r1] + s->size[r2];
                s->p[ r1 ] = r2;
	}
}


bool same_component(set_union *s, int s1, int s2)
{
	return ( find(s,s1) == find(s,s2) );
}



print_set_union(set_union *s)
{
        int i;                          /* counter */

        for (i=1; i<=s->n; i++)
                printf("%i  set=%d size=%d \n",i,s->p[i],s->size[i]);

        printf("\n");
}


