// bfs is to determine the shortest path from the source node to the other nodes
// if i made bfs and i found some nodes their values are 1e18 in the dist arrat then i cant reach this node from the source node
// u can print the shortest path form a node to a other by doing bfs then make a parent array and while pudhing in the queue make the parent of the u  = cur
const int sz = 2e5+5;
vector<ll>adj[sz];
ll dist[sz];

void bfs(){

    queue<ll>q;
    q.push(1);
    while(!q.empty()){
    ll cur = q.front();
        q.pop();
        for(auto u: adj[cur]){
            if(dist[u]==1e18)dist[u] = dist[cur]+1,q.push(u);
        }
    }

}

void solve() {

    for (int i = 0; i < sz; ++i) {
        dist[i+1] = 1e18;
    }
    ll n,m;cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        ll a,b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs();
}
