#include <iostream>
#include <vector>
// #include "bits/stdc++.h"
#include <climits>
#include <algorithm>
using namespace std;

long long int fun(int k,vector<long long int> &dp,vector<int> &coins)

{
    if(k < 0)
    return INT_MAX;
    if(dp[k]!=-1)
    return dp[k];
    if(k==0)
    return 0;

     int ans = INT_MAX;
    for(int i=0;i<coins.size();i++)
    {
        int pp = fun(k-coins[i],dp,coins);
        int tt =(pp!=INT_MAX)? pp+1:INT_MAX;
        ans = min(ans ,tt);
    }
    return dp[k]=ans;
}


int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> coins(n);
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    

    vector<long long int> dp(k+1,-1);
    if(fun(k,dp,coins)==INT_MAX)cout<<-1<<endl;
    else
   cout<<fun(k,dp,coins)<<endl;
}

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// // Auto vector input
// #define read_vec(name, size) vector<ll> name(size); for(int i = 0; i < size; i++) cin >> name[i];

// // Auto vector output
// #define print_vec(v) for (auto &x : v) cout << x << " "; cout << "\n";

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     t= 1;  // number of testcases

//     while (t--) {

//         int n, x;
//         cin >> n >> x;  // pair input

//         read_vec(a, n);  // auto-read vector v of size n
//         vector<ll> dp(x + 1, 0);
//         dp[0] = 0;
//      for(int i = 1; i <= x; i++)
//      {
//         ll  ans = INT_MAX;
//         for(int j=0;j<n;j++)
//         {
          
//             if( i - a[j] >= 0)
//             {
//                  ans = min(ans, 1+dp[i-a[j]]);
//             }
            
//         }
//         dp[i] = ans;

//      }
//      if(dp[x] < INT_MAX)
//         cout<<dp[x]<<"\n";
//         else
//         cout<<-1<<"\n";

//     }

//     return 0;
// }