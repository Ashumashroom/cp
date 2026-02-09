#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<char>> parent(n, vector<char>(m));

    queue<pair<int,int>> q;

    int sx, sy, ex, ey;

    // Find A and B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                sx = i; sy = j;
            }
            if (grid[i][j] == 'B') {
                ex = i; ey = j;
            }
        }
    }

    // Directions
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    char dir[4] = {'R', 'L', 'D', 'U'};

    q.push({sx, sy});
    vis[sx][sy] = 1;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (vis[nx][ny]) continue;
            if (grid[nx][ny] == '#') continue;

            vis[nx][ny] = 1;
            parent[nx][ny] = dir[i];
            q.push({nx, ny});
        }
    }

    if (!vis[ex][ey]) {
        cout << "NO\n";
        return 0;
    }

    // Reconstruct path
    string path;
    int x = ex, y = ey;

    while (x != sx || y != sy) {
        char d = parent[x][y];
        path.push_back(d);

        if (d == 'R') y--;
        else if (d == 'L') y++;
        else if (d == 'D') x--;
        else if (d == 'U') x++;
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";

    return 0;
}