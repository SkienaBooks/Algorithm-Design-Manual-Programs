/*	binomial.c
	Compute the binomial coefficients using dynamic programming 

	begun: February 10, 2002
	by: Steven Skiena
*/
#include <stdio.h>

#define	MAXN    100    /* largest n or m */

/* computer n choose m */

/* [[[ binomial_coeff_cut */
long binomial_coefficient(int n, int m) {
    int i, j;               /* counters */
    long bc[MAXN][MAXN];    /* table of binomial coefficient values */

    for (i = 0; i <= n; i++) {
        bc[i][0] = 1;
    }

    for (j = 0; j <= n; j++) {
        bc[j][j] = 1;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j < i; j++) {
            bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
        }
    }

    return(bc[n][m]);
}
/* ]]] */

int main(void) {
    int a, b;

    while (1) {
        scanf("%d %d", &a, &b);
        printf("%d\n", binomial_coefficient(a, b));
	}

    return 0;
}
