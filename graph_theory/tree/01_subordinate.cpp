#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <ctime>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// #include <bits/stdc++.h>
// using namespace std;




    int dfs(unordered_map<int,vector<int>>& mp, int node, vector<int>& dp) {
        if (dp[node] != -1) return dp[node];

        int ans = 0;
      

        for (auto child : mp[node]) {
            int t = dfs(mp, child, dp);
            ans += t;
           
        }

        return dp[node] = 1 + ans;
    }

    int main()
    {
    
        int  n;
        cin>>n;
        vector<int> parents(n+1);
        for(int i=2 ;i<=n;i++)
        {
            cin>>parents[i];
        }

        unordered_map<int, vector<int>> mp;
        for (int i = 2; i <= parents.size(); i++) {
      
                mp[parents[i]].push_back(i);
        }

        vector<int> dp(n+1, -1);
        dfs(mp, 1, dp);


       for (int i = 1; i < dp.size(); i++) {
           (dp[i]==-1)?cout<<0<<" ":cout<<dp[i]-1<<" ";
       }

    }

