#include <iostream>
#include <vector>
#include <functional> // for std::function
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0); // 0 = unvisited, 1 = color1, 2 = color2
        bool flag = true;

        function<void(int)> dfs = [&](int node) {
            for (int child : graph[node]) {
                if (vis[child] == 0) {
                    vis[child] = 3 - vis[node]; // alternate color
                    dfs(child);
                } else if (vis[child] == vis[node]) {
                    flag = false;
                    return;
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                vis[i] = 1; // start coloring with 1
                dfs(i);
            }
        }
        return flag;
    }
};

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> graph(n);

    cout << "Enter edges (0-based indexing):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // undirected graph
    }

    Solution sol;
    if (sol.isBipartite(graph)) {
        cout << "Graph is bipartite" << endl;
    } else {
        cout << "Graph is not bipartite" << endl;
    }

    return 0;
}
