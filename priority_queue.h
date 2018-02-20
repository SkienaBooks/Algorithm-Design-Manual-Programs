
/*	priority_queue.h

	Header file for queue implementation

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

#include "item.h"

#define PQ_SIZE 1000

/* [[[ priority_queue_struct_cut */
typedef struct {
    item_type q[PQ_SIZE+1];	    /* body of queue */
    int n;                      /* number of queue elements */
} priority_queue;
/* ]]] */

void pq_init(priority_queue *q);
int pq_parent(int n);
int pq_young_child(int n);
void pq_swap(priority_queue *q, int i, int j);
void bubble_up(priority_queue *q, int p);
void bubble_down(priority_queue *q, int p);
void pq_insert(priority_queue *q, item_type x);
item_type extract_min(priority_queue *q);
int empty_pq(priority_queue *q);
void print_pq(priority_queue *q);
void make_heap(priority_queue *q, item_type s[], int n);
void make_heap1(priority_queue *q, item_type s[], int n);
