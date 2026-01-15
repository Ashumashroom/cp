#include <iostream>      // for cin, cout
#include <vector>        // for vector
#include <map>           // for map
#include <set>           // for set
#include <algorithm>     // for sort, min, max, etc.
#include <climits>
const int MOD = 1e9 + 7;

using namespace std;
int fun(vector<string>&path,vector<vector<int>>&dp,int i ,int j)

{
     if(i==path.size()-1&&j==path[0].size()-1&&path[i][j]!='*')
     {
        return 1;
     }
     if(i>=path.size()||j>=path[0].size()||path[i][j]=='*')return 0;
     if(dp[i][j]!=-1)return dp[i][j];

    int right = fun(path,dp,i,j+1)%MOD;
    int down = fun(path,dp,i+1,j)%MOD;
    return dp[i][j] = ( (long long)right + (long long)down ) % MOD;

  }
int main()
{
    int n;cin>>n;
    vector<string>path(n);
    vector<vector<int>>dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        path[i]=s;
    }
    cout<<fun(path,dp,0 ,0)<<endl;
}