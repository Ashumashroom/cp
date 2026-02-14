#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int>p;
vector<int>level;
void dfs(vector<vector<int>>&adj,int node,vector<int>&vis)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(vis[it]==0)
        {
            level[it]=1+level[node];
            p[it]=node;
            dfs(adj,it,vis);
        }
    }
}
class BinaryLifting{

   vector<vector<int>>parent;
   int LOG;
   public:
  BinaryLifting(vector<int>& p, int n) {
        LOG = 20; // works up to ~4000 nodes
        parent.assign(LOG, vector<int>(n + 1, -1));

        // 2^0 parent
        for (int i = 1; i <= n; i++) {
            parent[0][i] = p[i];
        }

        // build binary lifting table
        for (int i = 1; i < LOG; i++) {
            for (int v = 1; v <= n; v++) {
                if (parent[i - 1][v] != -1) {
                    parent[i][v] = parent[i - 1][ parent[i - 1][v] ];
                }
            }
        }
    }

    int query(int node, int k) {
        for (int i = 0; i < LOG; i++) {
            if (node == -1) return -1;
            if (k & (1 << i)) {
                node = parent[i][node];
            }
        }
        return node;
    }

   int lca(int a, int b) {
        // 1️⃣ make depths equal
        if (level[a] < level[b]) swap(a, b);

        a = query(a, level[a] - level[b]);

        // 2️⃣ if same node
        if (a == b) return a;

        // 3️⃣ lift both together
        for (int i = LOG - 1; i >= 0; i--) {
            if (parent[i][a] != -1 && parent[i][a] != parent[i][b]) {
                a = parent[i][a];
                b = parent[i][b];
            }
        }

        // 4️⃣ parent is LCA
        return parent[0][a];
    }
    int disbtw(int a,int b)
    {
        int node = lca(a,b);
        return abs(level[node]-level[a])+abs(level[node]-level[b]);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;  // n nodes, m edges
    vector<int>vis(n+1,0);
    
    vector<vector<int>> adj(n + 1);
    p.assign(n+1,-1);
    level.assign(n+1,0);


    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);  // remove if graph is directed
    }
   dfs(adj,1,vis);
   BinaryLifting ashish = BinaryLifting(p,n);

   while(m--)
   {
    int x,y;
    cin>>x>>y;
   cout<<ashish.disbtw(x,y)<<endl;
   }


    return 0;
}