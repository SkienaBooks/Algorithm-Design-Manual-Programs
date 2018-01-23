
/*	tree-demo.c

	Driver for a binary search tree container implementation.

	by: Steven Skiena
	begun: September 5, 2005
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


#include "tree.h"
#include <stdio.h>
#include "bool.h"


tree *parent;				/* last node visited */

tree *init_tree()
{
        return(NULL);
}

bool empty_tree(tree *t)
{
        if (t == NULL) return (TRUE);
        else return (FALSE);
}

tree *search_tree(tree *l, item_type x)
{
	if (l == NULL) return(NULL);

	if (l->item == x) return(l);

	if (x < l->item)
		return( search_tree(l->left, x) );
	else
		return( search_tree(l->right, x) );
}


void insert_tree(tree **l, item_type x, tree *parent)
{
	tree *p;			/* temporary pointer */

	if (*l == NULL) {
		p = malloc( sizeof(tree) );
		p->item = x;
		p->left = p->right = NULL;
		p->parent = parent;
		*l = p;
		return;
	}

	if (x < (*l)->item)
		insert_tree(&((*l)->left), x, *l);
	else
		insert_tree(&((*l)->right), x, *l);
}


void print_tree(tree *l)
{
        if (l != NULL) {
		print_tree(l->left);
                printf("%d ",l->item);
		print_tree(l->right);
	}

}

tree *successor_descendant(tree *t)
{
	tree *succ;			/* successor pointer */

	if (t->right == NULL) return(NULL);

	succ = t->right;
	while (succ->left != NULL)
		succ = succ->left;
	return(succ);
}

tree *find_minimum(tree *t)
{
        tree *min;                     /* pointer to minimum */

        if (t == NULL) return(NULL);

        min = t;
        while (min->left != NULL)
                min = min->left;
        return(min);
}


tree *predecessor_descendant(tree *t)
{
        tree *pred;                     /* predecessor pointer */

        if (t->left == NULL) return(NULL);

        pred = t->left;
        while (pred->right != NULL)
                pred = pred->right;
        return(pred);
}

	
	

tree *delete_tree(tree *t, item_type x)
{
	tree *d;			/* node with key to delete */
	tree *p;			/* node to be physically deleted */
	item_type new_key;		/* key to overwrite deleted key */
	tree *child;			/* d's only child, if any */
	tree *search_tree();

	d = search_tree(t,x);

	if (d == NULL) {
		printf("Warning: key to be deleted %d is not in tree.\n",x);
		return(t);
	}

	if (d->parent == NULL) {	/* if d is the root */
		if ((d->left == NULL) && (d->right == NULL)) {
			free(d);
                	return NULL;	/* root-only tree */
          	}

	 	if (d->left != NULL) 	/* find node to physically delete */
			p = predecessor_descendant(d);
	  	else 
			p = successor_descendant(d);
	} else {
		if ((d->left == NULL) || (d->right == NULL)) {
			/* d has <=1 child, so try to find non-null child */
			if (d->left != NULL)
				child = d->left;
			else
	    			child = d->right;

	    		if ((d->parent)->left == d) {	/* fill null pointer */
	      			d->parent->left = child;
	    		}
	    		else {
	      			d->parent->right = child;
	    		}
	    	 	if (child != NULL) child->parent = d->parent;

	    	 	free(d);
			return(t);
	        }
		else {
			p = successor_descendant(d);	/* p has 2 children */
		}
	}

	new_key = p->item;		/* deal with simpler case of deletion */
	delete_tree(t, p->item);
        d->item = new_key;
        return (t);
}

/*         if ((t->left == NULL) && (t->right == NULL)) */
/*                 troot = NULL; */
/*         else */
/*                 troot = t;		/\* identify root of returned tree *\/ */


/* 	if (d->left != NULL) {		/\* copy rightmost left descendant over d *\/ */
/* 		p = d->left; */
/* 		while (p->right != NULL)  */
/* 			p = p->right; */
/* 		d->item = p->item; */
/* 		(p->parent)->right = p->left; */
/* 	} */
/* 	else if (d->right != NULL) {	/\* copy leftmost right descendant over d *\/ */
/* 		p = d->right; */
/* 		while (p->left != NULL) */
/* 			p = p->left; */
/* 		d->item = p->item; */
/* 		(p->parent)->left = p->right; */
/* 	} */
/* 	else {				/\* leaf deletion *\/ */
/* 		if (d->parent != NULL) { */
/* 			if ((d->parent)->left == d) */
/* 				(d->parent)->left == NULL; */
/* 			else */
/* 				(d->parent)->right == NULL; */
/* 		} */
/* 		p = d; */
/* 	} */

/* 	free(p); */
/* 	return(troot); */


main()
{
	char c;			/* input character */
	item_type d;			/* input item */
	tree *l;		/* tree under construction */
	tree *tmp;		/* returned tree from search */
	tree *search_tree();
	void insert_tree();

	l = init_tree();

	while (scanf("%c",&c) != EOF) {
		if (tolower(c) == 'p') {
			print_tree(l);
			printf("\n");
		}
		if (tolower(c) == 'i') {
			scanf("%d",&d);
			printf("new item: %d\n",d);
			insert_tree(&l,d, NULL);
		}
		if (tolower(c) == 's') {
			scanf("%d",&d);
			tmp = search_tree(l,d);
			if (tmp == NULL) 
				printf("item %d not found\n",d);
			else
				printf("item %d found\n",d);
		}
		if (tolower(c) == 'd') {
			scanf("%d",&d);
			printf(" deleting item %d\n",d);
                        l = delete_tree(l,d);
			print_tree(l);
                        printf("\n");
		}
	}
}


