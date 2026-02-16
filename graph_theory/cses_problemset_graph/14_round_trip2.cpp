#include <bits/stdc++.h>
using namespace std;

vector<int> parent, vis,cycle_flag;
int start = -1, endi = -1;

bool dfs(int node, vector<vector<int>>& adj) {
    vis[node] = 1;
    cycle_flag[node]=1;

    for (int it : adj[node]) {
       

        if (!vis[it]) {
            parent[it] = node;
            if (dfs(it, adj))
                return true;
        }
        else  if(cycle_flag[it]==1){
            // cycle found
            start = it;
            endi = node;
            return true;
        }
    }
    cycle_flag[node]=0;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    cycle_flag.assign(n+1,0);

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
       
    }

    vis.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, adj))
                break;
        }
    }

    if (start == -1) {
        cout <<"IMPOSSIBLE"<< "\n";
        return 0;
    }

    vector<int> cycle;
    

    cycle.push_back(start);
    for (int v = endi; v != start; v = parent[v])
        cycle.push_back(v);
    cycle.push_back(start);
    reverse(cycle.begin(),cycle.end());

    cout << cycle.size() << "\n";
    for (int x : cycle) cout << x << " ";
}