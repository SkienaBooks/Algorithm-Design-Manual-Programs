/*	permutations.c

	Construct all permutations via backtracking.

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

#include <stdio.h>
#include "bool.h"


bool finished = FALSE;
#define MAXCANDIDATES   100		/* max possible next extensions */
#define NMAX            100		/* maximum solution size */


void process_solution(int a[], int k, int input)
{
	int i;				/* counter */

	for (i=1; i<=k; i++) printf(" %d",a[i]);

	printf("\n");
}

int is_a_solution(int a[], int k, int n)
{
	return (k == n);
}

void make_move(int a[], int k, int n)
{
}

void unmake_move(int a[], int k, int n)
{
}


/*	What are possible elements of the next slot in the permutation?  */

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
	int i;				/* counter */
	bool in_perm[NMAX];		/* what is now in the permutation? */

	for (i=1; i<NMAX; i++) in_perm[i] = FALSE;
	for (i=1; i<k; i++) in_perm[ a[i] ] = TRUE;

	*ncandidates = 0;
	for (i=1; i<=n; i++) 
		if (in_perm[i] == FALSE) {
			c[ *ncandidates] = i;
			*ncandidates = *ncandidates + 1;
		}
}



void backtrack(int a[], int k, int input)
{
        int c[MAXCANDIDATES];           /* candidates for next position */
        int ncandidates;                /* next position candidate count */
        int i;                          /* counter */

        if (is_a_solution(a,k,input))
                process_solution(a,k,input);
        else {
                k = k+1;
                construct_candidates(a,k,input,c,&ncandidates);
                for (i=0; i<ncandidates; i++) {
                        a[k] = c[i];
                        make_move(a,k,input);

                        backtrack(a,k,input);
                        unmake_move(a,k,input);
                        if (finished) return;	/* terminate early */
                }
        }
}



int main()
{
	int a[NMAX];			/* solution vector */

	backtrack(a,0,0);
	backtrack(a,0,1);
	backtrack(a,0,2);
	backtrack(a,0,3);
}

