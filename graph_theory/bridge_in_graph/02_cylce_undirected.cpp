#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> cycle;
bool found = false;

void dfs(int u, int p, vector<int>& vis, vector<vector<int>>& adj) {
    if (found) return;
    vis[u] = 1;
    parent[u] = p;

    for (int v : adj[u]) {
        if (v == p) continue;

        if (!vis[v]) {
            dfs(v, u, vis, adj);
        }
        else {
            // cycle found (back edge)
            found = true;

            int cur = u;
            cycle.push_back(v);
            while (cur != v) {
                cycle.push_back(cur);
                cur = parent[cur];
            }
            cycle.push_back(v);
            reverse(cycle.begin(), cycle.end());
            return;
        }
    }
}

bool isCycleDFS(int n, vector<vector<int>>& adj) {
    vector<int> vis(n, 0);
    parent.assign(n, -1);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, -1, vis, adj);
            if (found) return true;
        }
    }
    return false;
}
bool bfs(int src, vector<int>& vis,
         vector<vector<int>>& adj,
         vector<int>& cycle) {

    queue<int> q;
    vector<int> parent(adj.size(), -1);

    vis[src] = 1;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                parent[v] = u;
                q.push(v);
            }
            else if (v != parent[u]) {
                // cycle found
                vector<int> path1, path2;
                int x = u, y = v;

                while (x != -1) {
                    path1.push_back(x);
                    x = parent[x];
                }
                while (y != -1) {
                    path2.push_back(y);
                    y = parent[y];
                }

                reverse(path1.begin(), path1.end());
                reverse(path2.begin(), path2.end());

                int i = 0;
                while (i < path1.size() && i < path2.size()
                       && path1[i] == path2[i]) i++;

                for (int j = path1.size() - 1; j >= i - 1; j--)
                    cycle.push_back(path1[j]);
                for (int j = i; j < path2.size(); j++)
                    cycle.push_back(path2[j]);

                return true;
            }
        }
    }
    return false;
}

bool isCycleBFS(int n, vector<vector<int>>& adj, vector<int>& cycle) {
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (bfs(i, vis, adj, cycle))
                return true;
        }
    }
    return false;
}