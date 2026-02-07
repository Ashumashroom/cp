#include <bits/stdc++.h>
using namespace std;

class Kosaraju {
public:
    int n;
    vector<vector<int>> adj, rev;
    vector<int> vis;
    stack<int> st;

    Kosaraju(int n) {
        this->n = n;
        adj.resize(n);
        rev.resize(n);
        vis.assign(n, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        rev[v].push_back(u); // reverse edge
    }

    // Step 1: DFS to fill stack by finish time
    void dfs1(int u) {
        vis[u] = 1;
        for (int v : adj[u]) {
            if (!vis[v])
                dfs1(v);
        }
        st.push(u);
    }

    // Step 3: DFS on reversed graph
    void dfs2(int u, vector<int>& component) {
        vis[u] = 1;
        component.push_back(u);
        for (int v : rev[u]) {
            if (!vis[v])
                dfs2(v, component);
        }
    }

    vector<vector<int>> getSCCs() {
        // Step 1
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                dfs1(i);
        }

        // Reset visited
        fill(vis.begin(), vis.end(), 0);

        // Step 3
        vector<vector<int>> sccs;
        while (!st.empty()) {
            int u = st.top();
            st.pop();

            if (!vis[u]) {
                vector<int> component;
                dfs2(u, component);
                sccs.push_back(component);
            }
        }
        return sccs;
    }
};