/*    substringedit.c

    Approximately match one string as a substring of another, where is s in t?

    by: Steven Skiena
    begun: March 26, 2002
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
#include <string.h>

#include "bool.h"
#include "editdistance.h"

cell m[MAXLEN+1][MAXLEN+1];         /* dynamic programming table */


/******************************************************************/

/*    For normal edit distance computation  */
/* [[[ goal_cell_288_cut */
void goal_cell(char *s, char *t, int *i, int *j) {
    int k;    /* counter */

    *i = strlen(s) - 1;
    *j = 0;

    for (k = 1; k < strlen(t); k++) {
        if (m[*i][k].cost < m[*i][*j].cost) {
            *j = k;
        }
    }
}
/* ]]] */

/* [[[ match_288_cut */
int match(char c, char d) {
    if (c == d) {
        return(0);
    }
    return(1);
}
/* ]]] */

int indel(char c) {
    return(1);
}

/* [[[ row_init_288_cut */
void row_init(int i, cell m[MAXLEN+1][MAXLEN+1]) {      /* what is m[0][i]? */
    m[0][i].cost = 0;       /* NOTE CHANGE */
    m[0][i].parent = -1;    /* NOTE CHANGE */
}
/* ]]] */

void column_init(int i, cell m[MAXLEN+1][MAXLEN+1]) {   /* what is m[i][0]? */
    m[i][0].cost = i;
    if (i > 0) {
        m[i][0].parent = DELETE;
    } else {
        m[0][i].parent = -1;
    }
}

/**********************************************************************/

void match_out(char *s, char *t, int i, int j) {
    if (s[i] == t[j]) {
        printf("M");
    } else {
        printf("S");
    }
}

void insert_out(char *t, int j) {
    printf("I");
}

void delete_out(char *s, int i) {
    printf("D");
}

/**********************************************************************/

int main(void) {
    int i, j;
    char s[MAXLEN], t[MAXLEN];    /* input strings */

    s[0] = t[0] = ' ';

    scanf("%s", &(s[1]));
    scanf("%s", &(t[1]));

    printf("matching cost = %d \n", string_compare(s, t, m));

    print_matrix(s, t, TRUE, m);
    printf("\n");
    print_matrix(s, t, FALSE, m);

    goal_cell(s, t, &i, &j);

    printf("%d %d\n", i, j);

    reconstruct_path(s, t, i, j, m);
    printf("\n");

    return 0;
}
