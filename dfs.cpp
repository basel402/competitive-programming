// nodes are vertices in a graph and edges are lines to connect the nodes 
// multigraph -> multiple lines between 2 nodes, complete graph -> from any node ther is a line to all other nodes
// connected graph -> from any node you can reach all other nodes , connectes component is a connected graph from a bigger unconnected graph
// tree -> connected graph, acyclic, undirected, n-1 edges
// represent a graph by using adj list and adj matrix and (edge list(from , to , weight), edge list is written as array of vectotr of pair)
// in grid problems use nx and ny arrays intead of using adj list to know connected cells, they are known you can add 1 or -1 or add 0 .. to know your connected cells instead of using great memory and time in adj list
// dfs and bfs are traversal algorithms on a graph, dfs pass by all nodes in a graph dont care about order it cares about how adj list is built
// to check if the graph is a tree you will check if it have n-1 edges and acyclic or it have n-1 edges and connected
// to check its acyclic you will loop on all nodes and check if vis and not the parent then there is a cycle and return else dfs 
// dfs time complexity is o(vert + edges)

// dfs code on a graph(tree,...)
const int sz = 2e5+5;
vector<ll>adj[sz];
vector<bool>vis(sz);
void dfs(int v){

    vis[v] = true;
    for(auto u : adj[v]){
        if(!vis[u])dfs(u);
    }
    
}

// dfs on only a tree (valid tree without cycles,...)
const int sz = 2e5+5;
vector<ll>adj[sz];
vector<bool>vis(sz);
void dfs(int v,int parent){
    
    for(auto u : adj[v]){
        if(u!=parent)dfs(u,v);
    }

}

// degree in a indirected graph is the size of adj lists and in directed it have indegree(number of edges going to this node) and out degreee(number of nodes coming out of this node)
// topo sort is sort based on prerequisites , the graph must be directed and acyclic
// bipartite graph is 2 teams each member in a team cant be connected with a member in the same team

// detect a cycle in a directed geaph
const int sz = 2e5+5;
vector<ll>adj[sz];
vector<bool>vis(sz);
vector<bool>ancestor(sz);
bool cycle = false;
void dfs(int v){

    vis[v] = true;
    for(auto u:adj[v]){
        if(ancestor[u])cycle = true;
        if(!vis[u])dfs(u);
    }
    ancestor[v] = false;
    
}
