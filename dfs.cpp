// nodes are vertices in a graph and edges are lines to connect the nodes 
// multigraph -> multiple lines between 2 nodes, complete graph -> from any node ther is a line to all other nodes
// connected graph -> from any node you can reach all other nodes , connectes component is a connected graph from a bigger unconnected graph
// tree -> connected graph, acyclic, undirected, n-1 edges
// represent a graph by using adj list and adj matrix and edge list(from , to , weight)
// in grid problems use nx and ny arrays intead of using adj list to know connected cells, they are known you can add 1 or -1 or add 0 .. to know your connected cells instead of using great memory and time in adj list
// dfs and bfs are traversal algorithms on a graph, dfs pass by all nodes in a graph dont care about order it cares about how adj list is built
