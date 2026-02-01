#include <bits/stdc++.h>
using namespace std;

static const int mod = 1e9 + 7;

vector<vector<int>> adj;
vector<int> dist;
vector<int> dp;
int n;

// DFS on shortest-path DAG
int dfs(int u) {
    if (u == n) return 1;
    if (dp[u] != -1) return dp[u];

    long long ways = 0;
    for (int v : adj[u]) {
        if (dist[u] + 1 == dist[v]) {
            ways = (ways + dfs(v)) % mod;
        }
    }
    return dp[u] = ways;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;

    adj.assign(n + 1, {});
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // STEP 1: BFS to compute shortest distances
    dist.assign(n + 1, INT_MAX);
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == INT_MAX) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // STEP 2 & 3: DFS + DP
    dp.assign(n + 1, -1);
    cout << dfs(1) << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

static const int mod = 1e9 + 7;

int solve(int n, vector<vector<int>> &adj) {
    queue<int> q;

    // dist[i] = shortest distance from 1 to i
    vector<int> dist(n + 1, INT_MAX);

    // ways[i] = number of shortest paths from 1 to i
    vector<int> ways(n + 1, 0);

    // start BFS from node 1
    q.push(1);
    dist[1] = 0;
    ways[1] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {

            // found a shorter path to v
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                ways[v] = ways[u];
                q.push(v);
            }
            // found another shortest path to v
            else if (dist[u] + 1 == dist[v]) {
                ways[v] = (ways[v] + ways[u]) % mod;
            }
        }
    }

    return ways[n];
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

    cout << solve(n, adj) << "\n";
    return 0;
}