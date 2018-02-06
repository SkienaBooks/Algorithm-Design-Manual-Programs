/*	war.c

	Simulation of the children's card game War 

	Read in cards with format value, suit, e.g. 4h
	ranked by orders 23456789TJQKA and cdhs

	by: Steven Skiena
	begun: January 18, 2002
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
#include <math.h>
#include <stdlib.h>
#include "bool.h"
#include "queue.h"

#define NGAMES	50
#define MAXSTEPS 100000

#define NCARDS	52	/* number of cards */
#define NSUITS	4	/* number of suits */


char values[] = "23456789TJQKA";
char suits[] = "cdhs";


/*	Return the suit and value of the given card.	 */

char suit(int card)
{
	return( suits[card % NSUITS] );
}

char value(int card)
{
	return( values[card/NSUITS] );
}


void print_card_queue(queue *q)
{
        int i,j;

        i=q->first;

        while (i != q->last) {
                /*printf("%2d ",q->q[i]);*/
                printf("%c%c ",value(q->q[i]),suit(q->q[i]));
                i = (i+1) % QUEUESIZE;
        }

        printf("%2d ",q->q[i]);
        printf("\n");
}


/* 	Rank the card with given value and suit.	*/

int rank_card(char value, char suit)
{
	int i,j;	/* counters */

	for (i=0; i<(NCARDS/NSUITS); i++)
		if (values[i]==value)
			for (j=0; j<NSUITS; j++)
				if (suits[j]==suit) 
					return( i*NSUITS + j );

	printf("Warning: bad input value=%c, suit=%c\n",value,suit);
}


void testcards(){
	int i;				/* counter */
	char suit(), value();		/* reconstructed card */

	for (i=0; i<NCARDS; i++)
		printf(" i=%d card[i]=%c%c rank=%d\n", i, value(i),
			suit(i), rank_card(value(i),suit(i)) );
}

/************************************************************/

void random_init_decks(queue *a, queue *b)
{
	int i;				/* counter */
	int perm[NCARDS+1];

	for (i=0; i<NCARDS; i=i+1) {
                perm[i] = i;
        }

	random_permutation(perm,NCARDS);

	init_queue(a);
	init_queue(b);

	for (i=0; i<NCARDS/2; i=i+1) {
		enqueue(a,perm[2*i]);
		enqueue(b,perm[2*i+1]);
	}

	print_card_queue(a);
	print_card_queue(b);

}

void war(queue *a, queue *b)
{
	int steps=0;			/* step counter */
	int x,y;			/* top cards */
	queue c;			/* cards involved in the war */
	bool inwar;			/* are we involved in a war? */

	inwar = FALSE;
	init_queue(&c);

/*printf("deck counts a=%d b=%d\n",a->count,b->count);*/


	while ((!empty_queue(a)) && (!empty_queue(b) && (steps < MAXSTEPS))) {
/*
print_card_queue(a);
print_card_queue(b);
*/
		steps = steps + 1;
		x = dequeue(a);
		y = dequeue(b);
		enqueue(&c,x);
		enqueue(&c,y);
		if (inwar) {
			inwar = FALSE;
		} else {
			if (value(x) > value(y)) 
				clear_queue(&c,a);
			else if  (value(x) < value(y)) 
				clear_queue(&c,b);
			else if (value(y) == value(x)) 
				inwar = TRUE;
		}
		/*printf("x=%d y=%d |a|=%d |b|=%d \n",x,y,a->count,b->count);*/
	}

/*printf("deck counts a=%d b=%d\n",a->count,b->count);*/

	if (!empty_queue(a) && empty_queue(b))
		printf("a wins in %d steps \n",steps);
	else if (empty_queue(a) && !empty_queue(b))
		printf("b wins in %d steps \n",steps);
	else if (!empty_queue(a) && !empty_queue(b))
		printf("game tied after %d steps, |a|=%d |b|=%d \n",
			steps,a->count,b->count);
	else
		printf("a and b tie in %d steps \n",steps);
}


clear_queue(queue *a, queue *b)
{
	/*printf("war ends with %d cards \n",a->count);*/
	while (!empty_queue(a))
		enqueue(b,dequeue(a));
}

int old_main(){
	queue a,b;
	int i;

	/*testcards();*/

	for (i=1; i<=NGAMES; i++) {
		random_init_decks(&a,&b);
		war(&a,&b);
	}
}


int main()
{
	queue decks[2];			/* player's decks */
	char value,suit,c;		/* input characters */
	int i;				/* deck counter */

	while (TRUE) {
	    for (i=0; i<=1; i++) {
       		init_queue(&decks[i]);

		while ((c = getchar()) != '\n') {
		    if (c == EOF) return -1;
		    if (c != ' ') {
			value = c;
			suit = getchar();
			enqueue(&decks[i],rank_card(value,suit));
		    }
      		}
	    }

	    war(&decks[0],&decks[1]);
	}
}
