class BridgeFinder {
public:
    int n;
    vector<vector<int>> adj;
    vector<int> tin, low, vis;
    int timer;
    vector<pair<int,int>> bridges;

    BridgeFinder(int n) {
        this->n = n;
        adj.resize(n);
        tin.resize(n, -1);
        low.resize(n, -1);
        vis.resize(n, 0);
        timer = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int parent) {
        vis[u] = 1;
        tin[u] = low[u] = timer++;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (!vis[v]) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                // bridge condition
                if (low[v] > tin[u]) {
                    bridges.push_back({u, v});
                }
            } else {
                // back edge
                low[u] = min(low[u], tin[v]);
            }
        }
    }

    vector<pair<int,int>> findBridges() {
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1);
            }
        }
        return bridges;
    }
};