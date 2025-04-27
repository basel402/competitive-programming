// bfs is to determine the shortest path from the source node to the other nodes
// if i made bfs and i found some nodes their values are 1e18 in the dist arrat then i cant reach this node from the source node
// u can print the shortest path form a node to a other by doing bfs then make a parent array all at first = -1 and then assign the parents to all the childs and then traverse from the last node until the parent of the cur node is -1 which is the root
// if the cost of the edges is 1 then do the normal bfs but if the cost of a certain edge is 0 then push front not push back so we will use deque and when comparing we will say if (nx,ny) > (f.first,f.sec) not +1 as usual then assigning it also without adding 1
// multiple source problems you will bfs from all the sources at the same time and minimize the dist as usual
// if you have a directed graph for course prerequisites and you want to detect cycles in it so you will remove all nodes with indegree 0 and if there are still remaining nodes then there is a cycle
// 0-1 bfs 
//khan algorithm for topo sort in lexicographically smallest answer you will use pq and insert in it all nodes with indeg 0 then whilw bfsing you will decrement the indegof cur node then if it is 0 push it in pq
// then while bfsing push the nodes in vector answer

// normal bfs with path print
ll n,m;
vector<ll>adj[sz];
vector<ll>dist(sz,1e9);
vector<ll>parent(sz,-1);

void bfs(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        ll a,b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<ll>q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()){
        ll front = q.front();
        q.pop();
        for(auto ch : adj[front]){
            if(dist[ch] > dist[front]+1){
                dist[ch] = dist[front]+1;
                q.push(ch);
                parent[ch] = front;
            }
        }
    }
    if(dist[n] == 1e9)cout << "IMPOSSIBLE\n";
    else{
        ll cur = n;
        vector<ll>path;
        while(cur!=-1){
            path.push_back(cur);
            cur = parent[cur];
        }
        reverse(path.begin(),path.end());
        cout << dist[n]+1 << endl;
        for(auto it : path)cout << it << ' ';
    }

}


// khans algorithm

const int sz = 2e5+5;
//vector<bool>vis(sz);
//vector<bool>ancestor(sz);
vector<ll>adj[sz];
vector<ll>indeg(sz);
vector<ll>ans;
//vector<ll>dist(sz,1e9);
ll n,m;
void bfs(){

    priority_queue<ll,vector<ll>,greater<>>pq;// the top is the smallest element
    for (int i = 1; i <=n; ++i) {
        if(!indeg[i])pq.push(i);
    }
    while(!pq.empty()){
        ll top = pq.top();
        ans.push_back(top);
        pq.pop();
        for(auto u : adj[top]){
            indeg[u]--;
            if(!indeg[u]){
                pq.push(u);
            }
        }
    }

}

void solve() {

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        ll a,b;cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    bfs();
    if(ans.size()!=n)cout << "Sandro fails.";
    else{
        for(auto it : ans)cout << it << ' ';
    }
    cout << endl;
}
signed main() {

    BeB_F2
    //seive();
   //testcases
        solve();


}

