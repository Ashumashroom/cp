#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll INF = 1e18;
int mod = 1e9+7;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;  // n nodes, m edges

    vector<vector<pair<int,int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b,c;
        cin >> a >> b>>c;
        adj[a].push_back({b,c});
    
    }
   priority_queue<
    pair<ll,ll>,
    vector<pair<ll,ll>>,
    greater<pair<ll,ll>>
> q;
    q.push({0,1});
    vector<ll>dis(n+1,INF);
    vector<ll>ways(n+1,0);
    vector<int>mini(n+1,1e9);
    vector<int>maxi(n+1,0);
    maxi[1]=0;
    mini[1]=0;
dis[1]=0;
ways[1]=1;

   while(!q.empty())
   {
        auto node = q.top();
        q.pop();
       ll  wt = node.first;
        int no= node.second;
        if(wt > dis[no])continue;
        for(auto it:adj[no])
        {
            if(dis[it.first] > dis[no]+it.second)
            {
                dis[it.first]=dis[no]+it.second;
                ways[it.first]=ways[no];
                mini[it.first]=1+mini[no];
                maxi[it.first]=1+maxi[no];
                q.push({dis[it.first],it.first});
            }
            else if(dis[it.first]==dis[no]+it.second)
            {
                ways[it.first]+=ways[no];
                ways[it.first]%=mod;
                if(mini[it.first]>mini[no]+1)
                {
                    mini[it.first]=mini[no]+1;
                }
                if(maxi[it.first] < maxi[no]+1)
                {
                    maxi[it.first]=1+maxi[no];
                }
                // q.push({dis[it.first],})
            }

        }

   }
cout<<dis[n]<<" "<<ways[n]<<" "<<mini[n]<<" "<<maxi[n]<<endl;
    return 0;
}