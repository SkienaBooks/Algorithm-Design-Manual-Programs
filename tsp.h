
#define	NMAX	1000			/* maximum number of points */

typedef struct {
	int x, y;			/* x and y coordinates of point */
} point;

typedef struct {
   int n;				/* how many points in problem? */
   point p[NMAX+1];			/* array of points */
} tsp_instance;

typedef struct {
   int n;				/* how many elements in permutation? */	
   int p[NMAX+1];			/* array if indices */
} tsp_solution;

double solution_cost(tsp_solution *s, tsp_instance *t);
void initialize_solution(int n, tsp_solution *s);
void copy_solution(tsp_solution *s, tsp_solution *t);
void random_solution(tsp_solution *s);
double transition(tsp_solution *s, tsp_instance *t, int i, int j);
