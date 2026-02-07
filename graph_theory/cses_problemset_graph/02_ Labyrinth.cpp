#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Auto vector input
#define read_vec(name, size) vector<ll> name(size); for(int i = 0; i < size; i++) cin >> name[i];

// Auto vector output
#define print_vec(v) for (auto &x : v) cout << x << " "; cout << "\n";

void dfs(int i, int j,
         vector<vector<int>>& dist,
         vector<vector<char>>& g,
         vector<vector<char>>& parent)
{
    int n = g.size();
    int m = g[0].size();

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    char dir[4] = {'R', 'L', 'D', 'U'};

    for (int d = 0; d < 4; d++) {
        int ni = i + dx[d];
        int nj = j + dy[d];

        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
        if (g[ni][nj] == '#') continue;

        if (dist[i][j] + 1 < dist[ni][nj]) {
            dist[ni][nj] = dist[i][j] + 1;
            parent[ni][nj] = dir[d];
            dfs(ni, nj, dist, g, parent);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<char>> parent(n, vector<char>(m, '?'));

    int si, sj, ei, ej;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'A') si = i, sj = j;
            if (g[i][j] == 'B') ei = i, ej = j;
        }

    dist[si][sj] = 0;
    dfs(si, sj, dist, g, parent);

    if (dist[ei][ej] == INT_MAX) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    cout << dist[ei][ej] << "\n";

  
    string path;
    int i = ei, j = ej;
    while (i != si || j != sj) {
        char c = parent[i][j];
        path.push_back(c);
        if (c == 'L') j++;
        else if (c == 'R') j--;
        else if (c == 'U') i++;
        else if (c == 'D') i--;
    }

    reverse(path.begin(), path.end());
    cout << path << "\n";

    return 0;
}