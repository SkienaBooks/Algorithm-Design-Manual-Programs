
# test script for "Programming Challenges" programs

./distance | diff - datafiles/distance-out
./war < datafiles/war-in | diff - datafiles/war-out
./name < datafiles/name-in | diff - datafiles/name-out
./sorting | diff - datafiles/sorting-out
./polly < datafiles/polly-in | diff - datafiles/polly-out
./bignum < datafiles/bignum-in | diff - datafiles/bignum-out
./gcd < datafiles/gcd-in | diff - datafiles/gcd-out
./primes < datafiles/primes-in | diff - datafiles/primes-out
./subsets | diff - datafiles/subsets-out
./permutations | diff - datafiles/permutations-out
./8-queens | diff - datafiles/8-queens-out
./bfs-demo < datafiles/grid | diff - datafiles/grid-bfs-demo-out
./dfs-demo < datafiles/grid | diff - datafiles/grid-dfs-demo-out
./connected < datafiles/connected-in | diff - datafiles/connected-out
./connected < datafiles/grid | diff - datafiles/grid-connected-out
./topsort < datafiles/grid | diff - datafiles/grid-topsort-out
./prim < datafiles/wgrid | diff - datafiles/wgrid-prim-out
./floyd < datafiles/wgrid | diff - datafiles/wgrid-floyd-out
./dijkstra < datafiles/wgrid | diff - datafiles/wgrid-dijkstra-out
./editbrute <datafiles/editbrute-in | diff - datafiles/editbrute-out
./stringedit <datafiles/stringedit-in | diff - datafiles/stringedit-out
./lcs <datafiles/stringedit-in | diff - datafiles/lcs-out
./substringedit < datafiles/substringedit-in | diff - datafiles/substringedit-out
./elevator < datafiles/elevator-in | diff - datafiles/elevator-out
./order | diff - datafiles/order-out
./plates <datafiles/plates1-in | diff - datafiles/plates1-out
./plates <datafiles/plates2-in | diff - datafiles/plates2-out
./plates <datafiles/plates3-in | diff - datafiles/plates3-out
./superman < datafiles/superin1 | diff - datafiles/superin1-out
./superman < datafiles/superin2 | diff - datafiles/superin2-out
./superman < datafiles/superin3 | diff - datafiles/superin3-out
./superman <datafiles/superin4 | diff - datafiles/superin4-out
./geotest < datafiles/geotest-in | diff - datafiles/geotest-out
./convex-hull < datafiles/chin | diff - datafiles/chin-out
./convex-hull < datafiles/chin1 | diff - datafiles/chin1-out
./convex-hull < datafiles/i.2 | diff - datafiles/i.2-out
./convex-hull < datafiles/i.4 | diff - datafiles/i.4-out
./convex-hull < datafiles/i.9 | diff - datafiles/i.9-out
./convex-hull < datafiles/i.10 | diff - datafiles/i.10-out
./convex-hull < datafiles/i.19 | diff - datafiles/i.19-out
./convex-hull < datafiles/convex-bad.10 | diff - datafiles/convex-bad.10-out
./convex-hull < datafiles/VDError-uniq.dat | diff - datafiles/VDError-uniq.dat-out
./convex-hull < datafiles/VDError.dat | diff - datafiles/VDError-uniq.dat-out
./triangulate < datafiles/tri1 | diff - datafiles/tri1-out
./triangulate < datafiles/tri2 | diff - datafiles/tri2-out
./triangulate < datafiles/tri3 | diff - datafiles/tri3-out
./cgtest < datafiles/cgtest-in | diff - datafiles/cgtest-out
./netflow < datafiles/netflow1-in | diff - datafiles/netflow1-out
./netflow < datafiles/netflow2-in | diff - datafiles/netflow2-out
./netflow < datafiles/netflow3-in | diff - datafiles/netflow3-out
./paths < datafiles/paths-graph  | diff - datafiles/paths-graph-out
#
#   Extra cases for "The Algorithm Design Manual"
#
./partition < datafiles/partition-data1 | diff - datafiles/partition-data1-out
./partition < datafiles/partition-data2 | diff - datafiles/partition-data2-out
./biconnected < datafiles/grid | diff - datafiles/biconnected-grid
# ./biconnected < datafiles/tree | diff - datafiles/biconnected-tree           # Articulation Vertex related issue
./biconnected < datafiles/art3 | diff - datafiles/biconnected-art3
# ./biconnected < datafiles/baase | diff - datafiles/biconnected-baase         # Articulation Vertex related issue
# ./biconnected < datafiles/clr-graph | diff - datafiles/biconnected-clr-graph # Articulation Vertex related issue
./strong < datafiles/g-1 | diff - datafiles/strong-g-1
./strong < datafiles/g-2 | diff - datafiles/strong-g-2
./strong < datafiles/g-3 | diff - datafiles/strong-g-3
./strong < datafiles/g-4 | diff - datafiles/strong-g-4
./strong < datafiles/g-5 | diff - datafiles/strong-g-5
./strong < datafiles/strong-clr | diff - datafiles/strong-clr-out
./bipartite < datafiles/grid | diff - datafiles/bipartite-grid
./bipartite < datafiles/tree | diff - datafiles/bipartite-tree
./bipartite < datafiles/art3 | diff - datafiles/bipartite-art3
./topsort1 < datafiles/grid | diff - datafiles/grid-topsort1-out
./matrix < datafiles/matrix-data1 | diff - datafiles/matrix-data1-out
./matrix < datafiles/matrix-data2 | diff - datafiles/matrix-data2-out
./list-demo < datafiles/list-in | diff - datafiles/list-out
./tree-demo < datafiles/list-in | diff - datafiles/treelist-out
./tree-demo < datafiles/t1.in | diff - datafiles/t1.out
