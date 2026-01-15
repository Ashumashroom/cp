#include <iostream>
#include <vector>
// #include "bits/stdc++.h"
#include <climits>
#include <algorithm>
using namespace std;
int const mod = 1e9+7;
// // without taking const it give tle because it const run at compile time meanst where ever mod is written it simply replace with its value at compile time / where if not eirtten it cheak on memory and put this increase number of ofpreation give tle

//  int fun(int k,vector<long long int> &dp,vector<int> &coins)

// {
//     if(k < 0)
//     return 0;
//     if(dp[k]!=-1)
//     return dp[k];
//     if(k==0)
//     return 1;

//      int ans = 0;
//     for(int i=0;i<coins.size();i++)
//     {
//         int pp = fun(k-coins[i],dp,coins);
    
//         ans +=(pp)%mod;
//         ans%=mod;
//     }
//     return dp[k]=ans%mod;
// }


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
  dp[0]=1;
    for(int i =1;i<=k;i++)
    {
         dp[i]=0;
         for(int j=0;j<n;j++)
         {
              if(i - coins[j]>=0)
              {
                dp[i] += dp[i - coins[j]]%mod;
                dp[i]%=mod;
              }
         }
    }
    
    cout<<dp[k]%mod<<endl;

}