#include <iostream>
#include <vector>
#include "bits/stdc++.h"
using namespace std;
int mod = 1e9+7;
long long int fun(int n,vector<long long int> &dp)

{
    if(n < 0)
    return 0;
    if(dp[n]!=-1)
    return dp[n];
    if(n==0)
    return 1;

    return dp[n]=(fun(n-1,dp)%mod+fun(n-2,dp)%mod+fun(n-3,dp)%mod+fun(n-4,dp)%mod+fun(n-5,dp)%mod+fun(n-6,dp)%mod)%mod;
}

int main()
{
    int n;
    cin>>n;
    vector<long long int> dp(n+1,-1);
    cout<<fun(n,dp)<<endl;
}