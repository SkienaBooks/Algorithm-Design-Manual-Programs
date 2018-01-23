
/*	list-demo.c

	Driver for a linked list-based container implementation.

	by: Steven Skiena
	begun: September 2, 2005
*/


/*
Copyright 2005 by Steven S. Skiena; all rights reserved. 

Permission is granted for use in non-commerical applications
provided this copyright notice remains intact and unchanged.

This program appears in my book:

"Programming Challenges: The Programming Contest Training Manual"
by Steven Skiena and Miguel Revilla, Springer-Verlag, New York 2003.

See our website www.programming-challenges.com for additional information.

This book can be ordered from Amazon.com at

http://www.amazon.com/exec/obidos/ASIN/0387001638/thealgorithmrepo/

*/


#include "list.h"
#include <stdio.h>
#include "bool.h"


list *init_list()
{
        return(NULL);
}

bool empty_list(list *l)
{
        if (l == NULL) return (TRUE);
        else return (FALSE);
}

list *search_list(list *l, item_type x)
{
	if (l == NULL) return(NULL);

	if (l->item == x)
		return(l);
	else
		return( search_list(l->next, x) );
}

list *predecessor_list(list *l, item_type x)
{
        if ((l == NULL) || (l->next == NULL)) {
		printf("Error: predecessor sought on null list.\n");
		return(NULL);
	}

        if ((l->next)->item == x)
                return(l);
        else
                return( predecessor_list(l->next, x) );
}


void insert_list(list **l, item_type x)
{
	list *p;			/* temporary pointer */

	p = malloc( sizeof(list) );
	p->item = x;
	p->next = *l;
	*l = p;
}

print_list(list *l)
{
        while (l != NULL) {
                printf("%d ",l->item);
		l = l->next;
	}

        printf("\n");
}


delete_list(list **l, item_type x)
{
	list *p;			/* item pointer */
	list *pred;			/* predecessor pointer */
	list *search_list(), *predecessor_list();

	p = search_list(*l,x);
	if (p != NULL) {
		pred = predecessor_list(*l,x);
		if (pred == NULL)	/* splice out out list */
			*l = p->next;
		else
			pred->next = p->next;

		free(p);		/* free memory used by node */
	}
}



main()
{
	char c;			/* input character */
	item_type d;		/* input item */
	list *l;		/* list under construction */
	list *tmp;		/* returned list from search */
	list *search_list();
	void insert_list();

	l = init_list();

	while (scanf("%c",&c) != EOF) {
		if (tolower(c) == 'p')
			print_list(l);
		if (tolower(c) == 'i') {
			scanf("%d",&d);
printf("new item: %d\n",d);
			insert_list(&l,d);
		}
		if (tolower(c) == 's') {
			scanf("%d",&d);
			tmp = search_list(l,d);
			if (tmp == NULL) 
				printf("item %d not found\n",d);
			else
				printf("item %d found\n",d);
		}
		if (tolower(c) == 'd') {
			scanf("%d",&d);
                        tmp = search_list(l,d);
                        if (tmp == NULL)
                                printf("item to delete %d not found\n",d);
			else
				printf("item %d deleted\n",d);
			delete_list(&l,d);
		}
	}
}


