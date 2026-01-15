#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;

int fun(int i,int j,vector<vector<int>>&dp)
{
    if(i==j)
    {
        return 0;
    }
 if(dp[i][j]!=-1)
 return dp[i][j];
  int ans = INT_MAX;
  for(int ii=1;ii<=i/2;ii++)
  {
    ans = min(ans,1+fun(ii,j,dp)+fun(i-ii,j,dp));
  }
  for(int jj=1;jj<=j/2;jj++)
  {
    ans = min(ans,1+fun(i,jj,dp)+fun(i,j-jj,dp));
  }
  
   return dp[i][j] = ans;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout<<fun(n,m,dp)<<endl;
    

}
