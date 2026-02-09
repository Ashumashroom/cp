#include <bits/stdc++.h>
using namespace std;

vector<int> parent, vis;
int start = -1, endi = -1;

bool dfs(int node, int par, vector<vector<int>>& adj) {
    vis[node] = 1;

    for (int it : adj[node]) {
        if (it == par) continue;

        if (!vis[it]) {
            parent[it] = node;
            if (dfs(it, node, adj))
                return true;
        }
        else {
            // cycle found
            start = it;
            endi = node;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vis.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, adj))
                break;
        }
    }

    if (start == -1) {
        cout <<"IMPOSSIBLE"<< "\n";
        return 0;
    }

    vector<int> cycle;
    cycle.push_back(start);
    for (int v = endi; v != start; v = parent[v])
        cycle.push_back(v);
    cycle.push_back(start);

    cout << cycle.size() << "\n";
    for (int x : cycle) cout << x << " ";
}