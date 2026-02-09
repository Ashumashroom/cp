#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int>ans;

bool fun(int node,vector<vector<int>>&adj,vector<int>&vis,int parent,vector<int>&cycle)
{
    vis[node]=1;
    cycle[node]=1;
    for(auto it:adj[node])
    {
        if(vis[it]==0 )
        {
             if(fun(it,adj,vis,node,cycle))
             {
                ans.push_back(it);
                break;
             }
        }
        if(vis[it]==1 && cycle[it]==1  && parent != it)return true;
    }
    cycle[node]=0;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;  // n nodes, m edges

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);  // remove if graph is directed
    }
    vector<int>vis(n+1,0);
    vector<int>cycle(n+1,0);
    fun(1,adj,vis,-1,cycle);
    cout<<ans.size();
    for(auto it:ans)
    {
        cout<<it<<endl;
    }
    

    // Write graph logic here (DFS / BFS / DSU / etc.)

    return 0;
}