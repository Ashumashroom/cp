#include <bits/stdc++.h>
using namespace std;

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

    vector<int> parent(n + 1, -1);
    vector<int> vis(n + 1, 0);

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    parent[1] = -1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int nxt : adj[node]) {
            if (!vis[nxt]) {
                vis[nxt] = 1;
                parent[nxt] = node;
                q.push(nxt);
            }
        }
    }

    if (!vis[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Reconstruct path
    vector<int> path;
    for (int cur = n; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int x : path) cout << x << " ";
    cout << "\n";

    return 0;
}