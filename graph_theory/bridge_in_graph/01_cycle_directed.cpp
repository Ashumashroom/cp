#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj) {
    vis[node] = 1;

    for (int neigh : adj[node]) {
        if (!vis[neigh]) {
            if (dfs(neigh, node, vis, adj))
                return true;
        }
        else if (neigh != parent) {
            // visited and not parent → cycle
            return true;
        }
    }
    return false;
}

bool isCycleDFS(int n, vector<vector<int>>& adj) {
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, vis, adj))
                return true;
        }
    }
    return false;
}
bool bfs(int src, vector<int>& vis, vector<vector<int>>& adj) {
    queue<pair<int,int>> q;
    q.push({src, -1});
    vis[src] = 1;

    while (!q.empty()) {
        auto [node, parent] = q.front();
        q.pop();

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                vis[neigh] = 1;
                q.push({neigh, node});
            }
            else if (neigh != parent) {
                // visited and not parent → cycle
                return true;
            }
        }
    }
    return false;
}

bool isCycleBFS(int n, vector<vector<int>>& adj) {
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (bfs(i, vis, adj))
                return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << (isCycleBFS(n, adj) ? "Cycle Found\n" : "No Cycle\n");
}