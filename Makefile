#	Steven Skiena
#	March 26, 2002
#	Makefile for all "Programming Challenges" Book Programs
#

# Copyright 2003 by Steven S. Skiena; all rights reserved. 
#
# Permission is granted for use in non-commerical applications
# provided this copyright notice remains intact and unchanged.
#
# These programs appear in my book:
#
# "Programming Challenges: The Programming Contest Training Manual"
# by Steven Skiena and Miguel Revilla, Springer-Verlag, New York 2003.
#
# See our website www.programming-challenges.com for additional information.
#
# This book can be ordered from Amazon.com at
#
# http://www.amazon.com/exec/obidos/ASIN/0387001638/thealgorithmrepo/


MAKEFILE = Makefile
SOURCES = backtrack.c 8-queens.c permutations.c subsets.c queue.c war.c \
	graph.c random.c sorting.c bfs-dfs.c bfs-demo.c dfs-demo.c \
	connected.c topsort.c wgraph.c prim.c dijkstra.c floyd.c findcycle.c \
	editdistance.c stringedit.c lcs.c substringedit.c geometry.c \
	superman.c convex-hull.c triangulate.c 10055.c distance.c name.c \
	polly.c gcd.c primes.c bignum.c editbrute.c elevator.c order.c \
	plates.c geotest.c cgtest.c netflow.c paths.c sudoku.c annealing.c \
	tsp.c fib.c partition.c  biconnected.c stack.c strong.c topsort1.c \
	bipartite.c priority_queue.c kruskal.c set_union.c list-demo.c \
	tree-demo.c matrix.c criterion_test.c
OBJECTS = backtrack.o 8-queens.o permutations.o subsets.o queue.o war.o \
	graph.o random.o sorting.o bfs-dfs.o bfs-demo.o dfs-demo.o \
	connected.o topsort.o wgraph.o prim.o dijkstra.o floyd.o findcycle.o \
	editdistance.o stringedit.o lcs.o substringedit.o geometry.o \
	superman.o convex-hull.o triangulate.o 10055.c distance.o name.o \
	polly.o gcd.o primes.o bignum.o editbrute.o elevator.o order.o \
	plates.o geotest.o cgtest.o netflow.o paths.o sudoku.o annealing.o \
	tsp.o fib.o partition.o biconnected.o stack.o strong.o topsort1.o \
	bipartite.o priority_queue.o kruskal.o set_union.o list-demo.o \
	tree-demo.o matrix.o criterion_test.o
BINARIES = 8-queens permutations subsets war sorting bfs-demo \
	dfs-demo connected topsort prim dijkstra floyd findcycle stringedit \
	lcs substringedit superman convex-hull triangulate 10055 distance name \
	polly gcd primes bignum editbrute elevator order plates geotest cgtest \
	netflow paths sudoku tsp fib partition biconnected strong topsort \
	bipartite kruskal matrix tree-demo criterion_test distance_test
INCLUDES = bool.h backtrack.h queue.h graph.h editdistance.h \
	   geometry.h annealing.h tsp.h stack.h priority_queue.h set_union.h \
	   list.h tree.h item.h


CC = gcc
CFLAGS = -ggdb # -O4 -g -DNDEBUG -pg
LFLAGS = -lm # -g -lm -pg

make:	$(BINARIES)
	
$(OBJECTS):     $(INCLUDES)
 
$(OBJECTS):     $(MAKEFILE)

all:	$(BINARIES)

kruskal:	kruskal.o set_union.o wgraph.o
		$(CC) -o $@ kruskal.o set_union.o wgraph.o $(LFLAGS)

bipartite:	bipartite.o queue.o graph.o bfs-dfs.o
		$(CC) -o $@ bipartite.o queue.o graph.o bfs-dfs.o $(LFLAGS)

topsort1:	topsort1.o queue.o graph.o stack.o bfs-dfs.o
		$(CC) -o $@ topsort1.o queue.o graph.o stack.o bfs-dfs.o $(LFLAGS)

strong:		strong.o bfs-dfs.o queue.o graph.o stack.o
		$(CC) -o $@ strong.o bfs-dfs.o queue.o graph.o stack.o $(LFLAGS)

biconnected:	biconnected.o bfs-dfs.o queue.o graph.o
		$(CC) -o $@ biconnected.o bfs-dfs.o queue.o graph.o $(LFLAGS)

partition:	partition.c
		$(CC) -o $@ partition.c $(LFLAGS)

fib:		fib.c
		$(CC) -o $@ fib.c $(LFLAGS)

tsp:		annealing.o random.o tsp.o 
		$(CC) -o $@ annealing.o random.o tsp.o $(LFLAGS)

sudoku:		sudoku.o backtrack.o
		$(CC) -o $@ sudoku.o backtrack.o $(LFLAGS)

8-queens:	backtrack.o 8-queens.o
		$(CC) -o $@ 8-queens.o backtrack.o $(LFLAGS)

paths:		backtrack.o paths.o graph.o
		$(CC) -o $@ paths.o backtrack.o graph.o $(LFLAGS)

permutations:	backtrack.o permutations.o
		$(CC) -o $@ permutations.o backtrack.o $(LFLAGS)

subsets:	backtrack.o subsets.o
		$(CC) -o $@ subsets.o backtrack.o $(LFLAGS)

sorting:	random.o queue.o priority_queue.o sorting.o
		$(CC) -o $@ random.o queue.o priority_queue.o sorting.o $(LFLAGS)

war:		queue.o random.o war.o
		$(CC) -o $@ queue.o random.o war.o $(LFLAGS)

bignum:		bignum.o
		$(CC) -o $@ bignum.o $(LFLAGS)

bfs-demo:	queue.o graph.o bfs-dfs.o bfs-demo.o
		$(CC) -o $@ queue.o graph.o bfs-dfs.o bfs-demo.o $(LFLAGS)

dfs-demo:	queue.o graph.o bfs-dfs.o dfs-demo.o
		$(CC) -o $@ queue.o graph.o bfs-dfs.o dfs-demo.o $(LFLAGS)

connected:	queue.o graph.o bfs-dfs.o connected.o
		$(CC) -o $@ queue.o graph.o bfs-dfs.o connected.o $(LFLAGS)

topsort:	queue.o graph.o topsort.o
		$(CC) -o $@ queue.o graph.o topsort.o $(LFLAGS)

findcycle:	queue.o graph.o bfs-dfs.o findcycle.o
		$(CC) -o $@ queue.o graph.o bfs-dfs.o findcycle.o $(LFLAGS)

prim:		wgraph.o prim.o
		$(CC) -o $@ wgraph.o prim.o $(LFLAGS)

dijkstra:	wgraph.o dijkstra.o
		$(CC) -o $@ wgraph.o dijkstra.o $(LFLAGS)

floyd:		floyd.o
		$(CC) -o $@ floyd.o $(LFLAGS)

editbrute:	editbrute.o stringedit.o
		$(CC) -o $@ editbrute.o stringedit.o $(LFLAGS)

stringedit:	editdistance.o stringedit.o
		$(CC) -o $@ editdistance.o stringedit.o $(LFLAGS)

lcs:		editdistance.o lcs.o
		$(CC) -o $@ editdistance.o lcs.o $(LFLAGS)

substringedit:	editdistance.o substringedit.o
		$(CC) -o $@ editdistance.o substringedit.o $(LFLAGS)

superman:	geometry.o superman.o
		$(CC) -o $@ geometry.o superman.o $(LFLAGS)

convex-hull:	geometry.o convex-hull.o
		$(CC) -o $@ geometry.o convex-hull.o $(LFLAGS)

triangulate:	geometry.o triangulate.o
		$(CC) -o $@ geometry.o triangulate.o $(LFLAGS)

10055:		10055.o
		$(CC) -o $@ 10055.o $(LFLAGS)

distance:	distance.o
		$(CC) -o $@ distance.o $(LFLAGS)

name:		name.o
		$(CC) -o $@ name.o $(LFLAGS)

polly:		polly.o
		$(CC) -o $@ polly.o $(LFLAGS)

gcd:		gcd.o
		$(CC) -o $@ gcd.o $(LFLAGS)

primes:		primes.o
		$(CC) -o $@ primes.o $(LFLAGS)

elevator:	elevator.o
		$(CC) -o $@ elevator.o $(LFLAGS)

plates:		plates.o
		$(CC) -o $@ plates.o $(LFLAGS)

order:		order.o
		$(CC) -o $@ order.o $(LFLAGS)

geotest:	geometry.o geotest.o
		$(CC) -o $@ geometry.o geotest.o $(LFLAGS)

cgtest:		geometry.o cgtest.o
		$(CC) -o $@ geometry.o cgtest.o $(LFLAGS)

netflow:	netflow.o queue.o
		$(CC) -o $@ netflow.o queue.o $(LFLAGS)

matrix:		matrix.o
		$(CC) -o $@ matrix.o $(LFLAGS)

list-demo:	list-demo.o
		$(CC) -o $@ list-demo.o $(LFLAGS)

tree-demo:	tree-demo.o
		$(CC) -o $@ tree-demo.o $(LFLAGS)

criterion_test:		criterion_test.o
		$(CC) -o $@ criterion_test.o $(LFLAGS) -lcriterion

distance_test:		./tests/distance_test.o
		$(CC) -o $@ ./tests/distance_test.o distance.o $(LFLAGS) -lcriterion

lint:	
	lint -h $(SOURCES)

backup:	$(SOURCES) $(INCLUDES)
	cp $(SOURCES) backup
	cp $(INCLUDES) backup
 
clean: 	
	rm -f core *.o a.out $(BINARIES)

tar:	
	make clean
	tar cvf /tmp/bookprograms.tar .

