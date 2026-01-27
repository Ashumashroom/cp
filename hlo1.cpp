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

    int t=1;

    while (t--) {

       int n;
       cin>>n;
       vector<int>a(n),b(n),c(n);
       map<int,vector<vector<int>>>mp;
       int max_val= 0;
       for(int i=0;i<n;i++)
       {
            cin>>a[i]>>b[i]>>c[i];
             max_val=max(max_val,b[i]);
            mp[b[i]].push_back({a[i],c[i]});
       }
       vector<int>dp(max_val+1,0);
       dp[0]=0;

        for(int i=1;i<=max_val;i++)
        { 
            vector<vector<int>>temp=mp[i];
            for(int j=0;j<temp.size();j++)
            {
               
           
                
                  int a = dp[temp[j][0]-1]+temp[j][1];
                
               dp[i]=max(dp[i],a);
            }
            dp[i]=max(dp[i],dp[i-1]);
        }
cout<<dp[max_val]<<endl;
    }

    return 0;
}