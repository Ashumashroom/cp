#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> dp;

void dfs(int u, int parent) {
    dp[u][0] = 0;
    dp[u][1] = 0;

    int sum = 0;
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        sum += max(dp[v][0], dp[v][1]);
    }

    dp[u][0] = sum;

    for (int v : adj[u]) {
        if (v == parent) continue;
        dp[u][1] = max(
            dp[u][1],
            1 + dp[v][0] + (sum - max(dp[v][0], dp[v][1]))
        );
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    adj.resize(n + 1);
    dp.assign(n + 1, vector<int>(2, 0));

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << "\n";
}