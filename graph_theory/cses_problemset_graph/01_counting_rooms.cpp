#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& g) {
    int n = g.size();
    int m = g[0].size();

    vis[i][j] = 1;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int d = 0; d < 4; d++) {
        int ni = i + dx[d];
        int nj = j + dy[d];

        if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
            if (g[ni][nj] == '.' && !vis[ni][nj]) {
                dfs(ni, nj, vis, g);
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.' && !vis[i][j]) {
                dfs(i, j, vis, g);
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}