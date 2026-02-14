#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;  // n nodes, m edges

    vector<vector<pair<int,int>>> adj(n + 1);
    vector<int>edges[m];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b >>c;
        adj[a].push_back({b,c});
        edges[i].push_back({a,b,c});

    }



    return 0;
}