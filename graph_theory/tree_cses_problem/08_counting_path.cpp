#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int>dis(n+1,0);

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
void dfs2(vector<vector<int>>&adj,int node,vector<int>&vis)
{
    
    vis[node]=1;
    for(auto it:adj[node])
    {
        dis[node]+=dis[it];
        dfs2(adj,it,vis);
    }

}
class binarylifting{
        vector<vector<int>>parent;
        vector<int>level;
        int log = 21;
         binarylifting(vector<int>&p,vector<int>&level)
         {
            int n = p.size();
            parent.assigh(n,-1);
            for(int i=0;i<n;i++)
            {
                parent[0][i]=p[i];
            }
            for(int i=1;i<log;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(parent[i-1][parent[i-1][j]]!=-1)
                    {
                        parent[i][j]=parent[i-1][parent[i-1][j]];
                    }
                }
            }
         }

        int query(int node, int k) {
        for (int i = 0; i < log; i++) {
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
        for (int i = log - 1; i >= 0; i--) {
            if (parent[i][a] != -1 && parent[i][a] != parent[i][b]) {
                a = parent[i][a];
                b = parent[i][b];
            }
        }

        // 4️⃣ parent is LCA
        return parent[0][a];
    }




};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;  // n nodes, m edges

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);  
    }
    vector<int>vis(n+1,0);
    dfs(adj,1,vis);
    binarylifting ashish = binarylifting(p,level);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        dis[a]++;
        dis[b]++;
        int lcanode = ashish.lca(a,b);
        dis[lcanode]--;
        parent[lcanode]--;
    }
    vector<int>vis2(n+1,0);

dfs2(adj,1,vis2);
for(auto it:dis)
{
    cout<<dis<<endl;
}
    


    return 0;
}