
/*    priority_queue.c

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

#include <stdio.h>

#include "bool.h"
#include "priority_queue.h"

/* [[[ pq_init_cut */
void pq_init(priority_queue *q) {
    q->n = 0;
}
/* ]]] */

/* [[[ pq_parent_cut */
int pq_parent(int n) {
    if (n == 1) {
        return(-1);
    }
    return((int) n/2);     /* implicitly take floor(n/2) */
}
/* ]]] */

/* [[[ pq_young_child */
int pq_young_child(int n) {
    return(2 * n);
}
/* ]]] */

void pq_swap(priority_queue *q, int i, int j) {
    item_type temp;    /* placeholder */

    temp = q->q[i];
    q->q[i] = q->q[j];
    q->q[j] = temp;
}

/* [[[ bubble_up_cut */
void bubble_up(priority_queue *q, int p) {
    if (pq_parent(p) == -1) {
        return;    /* at root of heap, no parent */
    }

    if (q->q[pq_parent(p)] > q->q[p]) {
        pq_swap(q, p, pq_parent(p));
        bubble_up(q, pq_parent(p));
    }
}
/* ]]] */

/* [[[ bubble_down_cut */
void bubble_down(priority_queue *q, int p) {
    int c;          /* child index */
    int i;          /* counter */
    int min_index;  /* index of lightest child */

    c = pq_young_child(p);
    min_index = p;

    for (i = 0; i <= 1; i++) { 
        if ((c + i) <= q->n) {
            if (q->q[min_index] > q->q[c + i]) {
                min_index = c + i;
            }
        }
    }

    if (min_index != p) {
        pq_swap(q, p, min_index);
        bubble_down(q, min_index);
    }
}
/* ]]] */

/* [[[ pq_insert_cut */
void pq_insert(priority_queue *q, item_type x) {
    if (q->n >= PQ_SIZE) {
        printf("Warning: priority queue overflow insert x=%d\n", x);
    } else {
        q->n = (q->n) + 1;
        q->q[q->n] = x;
        bubble_up(q, q->n);
    }
}
/* ]]] */

/* [[[ extract_min */
item_type extract_min(priority_queue *q) {
    int min = -1;    /* minimum value */

    if (q->n <= 0) {
        printf("Warning: empty priority queue.\n");
    } else {
        min = q->q[1];

        q->q[1] = q->q[q->n];
        q->n = q->n - 1;
        bubble_down(q, 1);
    }
    return(min);
}
/* ]]] */

int empty_pq(priority_queue *q) {
    if (q->n <= 0) {
        return (TRUE);
    }
    return (FALSE);
}

void print_pq(priority_queue *q) {
    int i;    /* counter */

    for (i = 1; i <= q->n; i++) {
        printf("%d ", q->q[i]);
    }

    printf("\n");
}

/* [[[ make_heap_cut */
void make_heap(priority_queue *q, item_type s[], int n) {
    int i;    /* counter */

    q->n = n;
    for (i = 0; i < n; i++) {
        q->q[i + 1] = s[i];
    }

    for (i = q->n; i >= 1; i--) {
         bubble_down(q, i);
    }
}
/* ]]] */

void make_heap1(priority_queue *q, item_type s[], int n) {
    int i;    /* counter */

    pq_init(q);
    for (i = 0; i < n; i++) {
        pq_insert(q, s[i]);
    }
}
