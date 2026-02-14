#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll inf = 1e18;
vector<ll>max_dis,min_dis;
void fun(int node, vector<vector<int>&adj)
{
     
    for(auto it:addj[node])
    {
        if(max_dis[it.first] > min_dis[node]+it.second || min_dis[it.first] > max_dis[node]+it.second)
        {
            max_dis[it.first]= min(max_dis[it.first] , min_dis[node]+it.second);
          min_dis[it.first]    = min( min_dis[it.first] , max_dis[node]+it.second);

            fun(it,adj);
        }
         
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;  // n nodes, m edges
    max_dis.assign(n+1,inf);
    min_dis.assign(n+1,inf);

    vector<vector<piar<int,int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b,c;
        cin >> a >> b>>c;
        adj[a].push_back({b,c});
        
   
    }
cout<<min(max_dis[n],min_dis[n]);
  

    return 0;
}