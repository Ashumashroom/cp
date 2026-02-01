#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

// Auto vector input
#define read_vec(name, size) vector<ll> name(size); for(int i = 0; i < size; i++) cin >> name[i];

// Auto vector output
#define print_vec(v) for (auto &x : v) cout << x << " "; cout << "\n";


int solve(int n,vector<vector<int>> &adj){
    queue<int> q;
    vector<int> vis(n+1,0);
    q.push(1);
    dis[1]=0;
    vector<int> ways(n+1,0);
    ways[1]=1;
    while(!q.empty()){
        int ele=q.front();
        q.pop();
        for(auto it:adj[ele]){
            if(vis[it]==0){
              
                q.push(it);
            }
            else{
                ways[node]+=(ways[it] %mod);
                ways[node]%=mod;
            }

        }
    }
    return ways[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    t=1;
    while (t--) {
      int n,m;
      cin>>n>>m;
    vector<vector<int>> adj(n+1);
      for(int i=0;i<m;i++)
      {
          int a,b;
          cin>>a>>b;
          adj[a].push_back(b);
          adj[b].push_back(a);
      }
      cout<<solve(n,adj)<<endl;

    }

    return 0;
}