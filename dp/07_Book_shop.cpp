#include <iostream>      // for cin, cout
#include <vector>        // for vector
#include <map>           // for map
#include <set>           // for set
#include <algorithm>     // for sort, min, max, etc.
#include <climits>
const int MOD = 1e9 + 7;

using namespace std;
int fun(int a[],int b[],int ind,int k,int n,vector<vector<int>>& dp)
{
   if(ind == n)return 0;
   if(k <= 0)return 0;
   if(dp[ind][k] != -1)return dp[ind][k];
   int take = 0;
   if(a[ind] <= k)
   {
       take = b[ind] + fun(a,b,ind+1,k-a[ind],n,dp);
   }
   int notTake = fun(a,b,ind+1,k,n,dp);
   return dp[ind][k] = max(take,notTake);
}


int main()
{
    int n,k;cin>>n>>k;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
    cout<<fun(a,b,0,k,n,dp)<<endl;

}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     vector<int> a(n), b(n);
//     for (int i = 0; i < n; i++) cin >> a[i];   // weights
//     for (int i = 0; i < n; i++) cin >> b[i];   // values

//     // dp[i][j] = max value using first i items with capacity j
//     vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

//     for (int i = 1; i <= n; i++) {
//         for (int j = 0; j <= k; j++) {
//             dp[i][j] = dp[i - 1][j];  // not take
//             if (a[i - 1] <= j) {
//                 dp[i][j] = max(dp[i][j], b[i - 1] + dp[i - 1][j - a[i - 1]]);
//             }
//         }
//     }

//     cout << dp[n][k] << endl;
//     return 0;
// }
