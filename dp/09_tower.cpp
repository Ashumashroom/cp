#include <iostream>      // for cin, cout
#include <vector>        // for vector
#include <map>           // for map
#include <set>           // for set
#include <algorithm>     // for sort, min, max, etc.
#include <climits>
using namespace std;
int fun(int i,int j,vector<vector<int>>&dp)
{
    if(i==0 && j==0)
    {
        return 1;
    }
    if(i<0||j<0)
    {
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int ans = 0;
    for(int  ii = 1;ii<=i ;ii++)
    {
        for(int jj = 1;jj<=j;jj++)
        {
            ans+=fun(i-ii,j-jj,dp);
        }
    }
    return   dp[i][j] =ans;

}
int main()
{
    int t;
    int N = 1e6+1;
    vector<vector<int>>dp(N,vector<int>(N,-1));



    cin>>t;while(t--)
    {
        int n;
         cout<<dp[n][n]<<endl;
    }
    
}