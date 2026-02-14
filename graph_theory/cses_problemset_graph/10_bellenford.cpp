#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);

const int INF = 1e18;

// DFS to mark reachable nodes
void dfs(vector<vector<int>>& g, vector<int>& vis, int u) {
    vis[u] = 1;
    for(auto v : g[u]) {
        if(!vis[v])
            dfs(g, vis, v);
    }
}

int32_t main() {
    fast

    int n, m;
    cin >> n >> m;

    vector<vector<int>> forward(n+1);
    vector<vector<int>> reverse_g(n+1);
    vector<tuple<int,int,int>> edges;

    // Read edges
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        forward[u].push_back(v);
        reverse_g[v].push_back(u);

        edges.push_back({u, v, -w}); // negate weight
    }

    // Mark nodes reachable from 1
    vector<int> vis(n+1, 0);
    dfs(forward, vis, 1);

    // Mark nodes that can reach n
    vector<int> vis1(n+1, 0);
    dfs(reverse_g, vis1, n);

    // Bellman-Ford
    vector<int> dist(n+1, INF);
    dist[1] = 0;

    bool updated = false;

    for(int i = 1; i <= n; i++) {
        updated = false;

        for(auto [u, v, w] : edges) {

            if(vis[u] && vis1[v] && dist[u] != INF 
               && dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
                updated = true;
            }
        }
    }

    // If updated in nth iteration → negative cycle
    if(updated) {
        cout << -1 << "\n";
    }
    else {
        cout << -dist[n] << "\n";  // restore max value
    }

    return 0;
}