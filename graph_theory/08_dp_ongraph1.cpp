
#include "bits/stdc++.h"
using namespace std;
 
#define int long long int
#define double long double
#define endl '\n'
 
const int MOD = 1000000007;
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    int n,m;
    cin>>n>>m;
    vector<int> graph[n+1];
    for (int i = 0; i < m; i++) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
 
    vector<int> dp(n+1,-1);
    vector<int> maxChild(n+1);
    dp[n]=1;
 
    function<int(int)> dfs = [&](int node) -> int {
        if (node==n) return 1;
        if (dp[node]==-1) {
            dp[node] = LLONG_MIN;
            for(int child: graph[node]) {
                int newdist = 1 + dfs(child);
                if (newdist > dp[node]) {
                    dp[node] = newdist;
                    maxChild[node] = child;
                }
            }
 
        }
        return dp[node];
    };
 
    int ans = dfs(1);
 
    if (ans>=0) {
        cout<<ans<<endl;
        int node = 1;
        while (node!=n) {
            cout<<node<<" ";
            node = maxChild[node];
        }
        cout<<node<<endl;
    } else {
        cout<<"IMPOSSIBLE\n";
    }
 
    return 0;
}