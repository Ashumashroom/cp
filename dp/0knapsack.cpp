#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Auto vector input
#define read_vec(name, size) vector<ll> name(size); for(int i = 0; i < size; i++) cin >> name[i];

// Auto vector output
#define print_vec(v) for (auto &x : v) cout << x << " "; cout << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t =1;

    while (t--) {

        int n, w;
        cin >> n >> w;  // pair input
vector<int>value(n);
vector<int>weight(n);
        for(int i=0;i<n;i++){
            cin>>weight[i]>>value[i];
        }
        vector<vector<ll>>dp(n+1,vector<ll>(w+1,0));
   for(int i=1;i<=n;i++)
   {
    for(int j=0;j<=w;j++)
    {
        if(weight[i-1]<=j)
        {
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i-1]]+value[i-1]);
        }
        else{
            dp[i][j]=dp[i-1][j];
        }
    }
   }

    cout << dp[n][w] << "\n";

    return 0;
}
}