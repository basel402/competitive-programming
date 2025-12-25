#include <bits/stdc++.h>
using namespace std;

/* ===================== DSU ===================== */

const int MAXN = 200005;

int parent[MAXN], sz[MAXN];

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

/* ===================== KRUSKAL ===================== */

struct Edge {
    int u, v, w;
};

vector<Edge> edges;
vector<Edge> mst_edges;

long long kruskal_min(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.w < b.w;
         });

    long long cost = 0;
    int cnt = 0;
    mst_edges.clear();

    for (auto e : edges) {
        if (union_set(e.u, e.v)) {
            cost += e.w;
            mst_edges.push_back(e);
            cnt++;
        }
    }

    if (cnt != n - 1) return -1; // MST does not exist
    return cost;
}

/* ===================== MAXIMUM MST ===================== */

long long kruskal_max(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.w > b.w;
         });

    long long cost = 0;
    int cnt = 0;

    for (auto e : edges) {
        if (union_set(e.u, e.v)) {
            cost += e.w;
            cnt++;
        }
    }

    if (cnt != n - 1) return -1;
    return cost;
}

/* ===================== PRIM ===================== */

vector<pair<int,int>> adj[MAXN];
bool used[MAXN];

long long prim(int n) {
    priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

    memset(used, false, sizeof(used));

    pq.push({0, 1});
    long long cost = 0;
    int cnt = 0;

    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();

        if (used[v]) continue;
        used[v] = true;
        cost += w;
        cnt++;

        for (auto [to, wt] : adj[v]) {
            if (!used[to])
                pq.push({wt, to});
        }
    }

    if (cnt != n) return -1;
    return cost;
}

/* ===================== MAIN ===================== */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    edges.clear();
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    long long min_mst = kruskal_min(n);
    if (min_mst == -1)
        cout << "MST does not exist\n";
    else {
        cout << "Minimum MST cost = " << min_mst << "\n";
        cout << "MST edges:\n";
        for (auto e : mst_edges)
            cout << e.u << " " << e.v << " " << e.w << "\n";
    }

    long long max_mst = kruskal_max(n);
    if (max_mst != -1)
        cout << "Maximum MST cost = " << max_mst << "\n";

    long long prim_mst = prim(n);
    if (prim_mst != -1)
        cout << "Prim MST cost = " << prim_mst << "\n";

    return 0;
}
