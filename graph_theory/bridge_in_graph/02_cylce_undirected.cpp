#include <bits/stdc++.h>
using namespace std;

bool isCycleBFS(int n, vector<vector<int>>& adj) {
    vector<int> indeg(n, 0);

    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            indeg[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0)
            q.push(i);
    }

    int cnt = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cnt++;

        for (int nbr : adj[node]) {
            indeg[nbr]--;
            if (indeg[nbr] == 0)
                q.push(nbr);
        }
    }

    return cnt != n; // cycle if not all nodes processed
}

bool dfs(int node, vector<int>& state, vector<vector<int>>& adj) {
    state[node] = 1; // visiting

    for (int nbr : adj[node]) {
        if (state[nbr] == 0) {
            if (dfs(nbr, state, adj))
                return true;
        }
        else if (state[nbr] == 1) {
            return true; // back edge → cycle
        }
    }

    state[node] = 2; // done
    return false;
}

bool isCycleDFS(int n, vector<vector<int>>& adj) {
    vector<int> state(n, 0);

    for (int i = 0; i < n; i++) {
        if (state[i] == 0) {
            if (dfs(i, state, adj))
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
        adj[u].push_back(v); // directed edge
    }

    cout << (isCycleDFS(n, adj) ? "Cycle Found\n" : "No Cycle\n");
}