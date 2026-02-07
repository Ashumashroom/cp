#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timer = 0;

    void dfs(int u, int parent,
             vector<int>& tin,
             vector<int>& low,
             vector<int>& vis,
             vector<int>& isArt,
             vector<vector<int>>& adj) {

        vis[u] = 1;
        tin[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (!vis[v]) {
                dfs(v, u, tin, low, vis, isArt, adj);
                low[u] = min(low[u], low[v]);

                // articulation condition (non-root)
                if (parent != -1 && low[v] >= tin[u]) {
                    isArt[u] = 1;
                }
                children++;
            } else {
                // back edge
                low[u] = min(low[u], tin[v]);
            }
        }

        // articulation condition (root)
        if (parent == -1 && children > 1) {
            isArt[u] = 1;
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& adj) {
        vector<int> tin(V, -1), low(V, -1), vis(V, 0), isArt(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, tin, low, vis, isArt, adj);
            }
        }

        vector<int> res;
        for (int i = 0; i < V; i++) {
            if (isArt[i]) res.push_back(i);
        }

        return res;  // articulation points
    }
};