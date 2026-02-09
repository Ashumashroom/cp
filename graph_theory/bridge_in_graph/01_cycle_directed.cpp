#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> cycle_nodes;
int cycle_start = -1, cycle_end = -1;

bool dfs(int node, vector<int>& state, vector<vector<int>>& adj) {
    state[node] = 1; // visiting

    for (int nbr : adj[node]) {
        if (state[nbr] == 0) {
            parent[nbr] = node;
            if (dfs(nbr, state, adj))
                return true;
        }
        else if (state[nbr] == 1) {
            // back edge found → cycle
            cycle_start = nbr;
            cycle_end = node;
            return true;
        }
    }

    state[node] = 2; // done
    return false;
}

bool isCycleDFS(int n, vector<vector<int>>& adj) {
    vector<int> state(n, 0);
    parent.assign(n, -1);

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

    if (isCycleDFS(n, adj)) {
        cout << "Cycle Found\n";

        // reconstruct cycle
        cycle_nodes.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v]) {
            cycle_nodes.push_back(v);
        }
        cycle_nodes.push_back(cycle_start);
        reverse(cycle_nodes.begin(), cycle_nodes.end());

        cout << "Cycle nodes: ";
        for (int x : cycle_nodes)
            cout << x << " ";
        cout << "\n";
    } else {
        cout << "No Cycle\n";
    }

    return 0;
}