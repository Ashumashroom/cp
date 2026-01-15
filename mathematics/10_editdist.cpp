#include <iostream>      // for cin, cout
#include <vector>        // for vector
#include <map>           // for map
#include <set>           // for set
#include <algorithm>     // for sort, min, max, etc.
#include <climits>
using namespace std;
// if only insertion and deletion then we use operations=(∣s∣−L)+(∣t∣−L) but there is replacement 
int fun(const string &s, const string &t, int i, int j, vector<vector<int>>&dp)
{
    if(i==s.size() || j==t.size())
    {
        return max(s.size()-i,t.size()-j);
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans =INT_MAX;
    if(s[i]==t[j])
    {
        ans =min(ans,fun(s,t,i+1,j+1,dp));
    }
    else{
    ans = min(ans, 1+ fun(s,t,i+1,j,dp));
    ans = min(ans,1+ fun(s,t,i,j+1,dp));
    ans = min(ans,1+ fun(s,t,i+1,j+1,dp));
    }
    return dp[i][j] = ans;
}
        
int main()
{
    string s;
    string t;
    cin>>s>>t;
    vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));

   int tt = fun(s,t,0,0,dp);
   cout<<tt<<endl;

}