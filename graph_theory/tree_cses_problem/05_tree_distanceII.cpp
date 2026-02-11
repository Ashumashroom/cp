#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll>nodenumber;
vector<ll>dis;
vector<ll>ans;
int n;
ll fun(vector<vector<int>>&adj,vector<int>&vis,int node)
{
    vis[node]=1;
    ll ans = 0;
   
    for(auto it:adj[node])
    {
        if(vis[it]==0)
        {
            dis[it]=1+dis[node];
            ans += fun(adj,vis,it); 
        }
    }
    
    return nodenumber[node] = ans+1;
}
void fun2(vector<vector<int>>&adj,vector<int>&vis,int node)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(vis[it]==0)
        {
             ans[it]=ans[node]-nodenumber[it]+n-nodenumber[it];
                fun2(adj, vis, it); 
           
        }
    }
    return ;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);  // remove if graph is directed
    }
    vector<int>vis(n+1,0);
    vector<int>vis2(n+1,0);

nodenumber.resize(n+1);
dis.resize(n+1);
ans.resize(n+1);
dis[1]=0;
 ll total_dis = 0;
 fun(adj,vis,1);
for(int i=1;i<=n;i++)
{
    total_dis+=dis[i];
    // cout<<"nn"<<nodenumber[i]<<" ";
}
cout<<endl;

ans[1]=total_dis;
fun2(adj,vis2,1);

for(int i=1;i<=n;i++)
{
    cout<<ans[i]<<endl;
}
    return 0;
}