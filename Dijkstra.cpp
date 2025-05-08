// this algo is like bfs but for weighted edges like 0-1 bfs, we used to push back and front bec we only have 2 values 0 or 1 but if we have more so we should push inside or front or back or ........ 
// this algo for non negative weights, time complexity -> o(nlog(n) + mlog(n)) 
// because every tune un the loop of adj u will push all edges so m edges using pq is mlog(n) and every time u pop node so nlog(n)
// dense graph have so many edges so its inefficient to use dijkstra , sparse graph have not many edges so we can use dijkstra

void solve() {

    ll n,m;cin >> n >> m;
    vector<pair<ll,ll>>adj[n+1];
    for (int i = 0; i < m; ++i) {
        ll a,b,c;cin >> a >> b >> c;
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }
    vector<ll>dist(n+1,1e9);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>q;
    q.push({0,1});
    dist[1] = 0;
    while(!q.empty()){
        ll fr = q.top().second,val = q.top().first;
        q.pop();
        if(dist[fr] < val)continue;
        for(auto u :adj[fr]){
            if(dist[u.first] > dist[fr] + u.second){
                dist[u.first] = dist[fr] + u.second;
                q.push({dist[u.first],u.first});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << endl;
    }

}
