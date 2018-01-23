
/*	stack.c

	Implementation of a LIFO stack abstract data type.

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


#include "stack.h"
#include "bool.h"


init_stack(stack *s)
{
        s->top = -1;
        s->count = 0;
}


push(stack *s, int x)
{
        if (s->count >= STACKSIZE)
		printf("Warning: stack overflow push x=%d\n",x);
        else {
		s->top = s->top + 1;
		s->s[ s->top ] = x;
                s->count = s->count + 1;
        }
}

int pop(stack *s)
{
        int x;

        if (s->count <= 0) printf("Warning: empty stack pop.\n");
        else {
                x = s->s[ s->top ];
                s->top = s->top - 1;
                s->count = s->count - 1;
        }

        return(x);
}

int empty_stack(stack *s)
{
        if (s->count <= 0) return (TRUE);
        else return (FALSE);
}

print_stack(stack *s)
{
        int i;				/* counter */

	for (i=(s->count-1); i>=0; i--)
                printf("%d ",s->s[i]);

        printf("\n");
}


