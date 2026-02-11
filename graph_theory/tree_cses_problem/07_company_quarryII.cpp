#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> level;

void dfs(int node, int parent, int depth) {
    level[node] = depth;
    for (int child : adj[node]) {
        if (child == parent) continue;
        dfs(child, node, depth + 1);
    }
}

class BinaryLifting {
    vector<vector<int>> parent;
    int LOG;

public:
    BinaryLifting(vector<int>& p, int n) {
        LOG = 12; // works up to ~4000 nodes
        parent.assign(LOG, vector<int>(n + 1, -1));

        // 2^0 parent
        for (int i = 1; i <= n; i++) {
            parent[0][i] = p[i];
        }

        // build binary lifting table
        for (int i = 1; i < LOG; i++) {
            for (int v = 1; v <= n; v++) {
                if (parent[i - 1][v] != -1) {
                    parent[i][v] = parent[i - 1][ parent[i - 1][v] ];
                }
            }
        }
    }

    int query(int node, int k) {
        for (int i = 0; i < LOG; i++) {
            if (node == -1) return -1;
            if (k & (1 << i)) {
                node = parent[i][node];
            }
        }
        return node;
    }

    int lca(int a, int b) {
        // 1️⃣ make depths equal
        if (level[a] < level[b]) swap(a, b);

        a = query(a, level[a] - level[b]);

        // 2️⃣ if same node
        if (a == b) return a;

        // 3️⃣ lift both together
        for (int i = LOG - 1; i >= 0; i--) {
            if (parent[i][a] != -1 && parent[i][a] != parent[i][b]) {
                a = parent[i][a];
                b = parent[i][b];
            }
        }

        // 4️⃣ parent is LCA
        return parent[0][a];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> p(n + 1, -1);
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
    }

    adj.assign(n + 1, {});
    level.assign(n + 1, 0);

    // build tree
    for (int i = 2; i <= n; i++) {
        adj[p[i]].push_back(i);
    }

    // root = 1
    dfs(1, -1, 0);

    BinaryLifting bl(p, n);

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << bl.lca(a, b) << '\n';
    }

    return 0;
}