#include <iostream>      // for cin, cout
#include <vector>        // for vector
#include <map>           // for map
#include <set>           // for set
#include <algorithm>     // for sort, min, max, etc.
#include <climits>
using namespace std;
int fun(string s,vector<int>&dp)
{
    if(s == "0" )return 0;
    if(s.size() == 1)
    return 1;
    int n = stoi(s);
    if(dp[n]!=-1)return dp[n];
   int ans = INT_MAX;
   for(auto c : s)
   {
      if (c == '0') continue; 
    int ttt =  fun(to_string(n - (c-'0')),dp);
       int tt = (ttt == INT_MAX)?ttt:ttt+1;
        ans = min(ans,tt);
   }

return dp[n]=ans;
}
int main()
{
    int n;cin>>n;
    string s = to_string(n);
    vector<int>dp(n+1,-1);
    cout<<fun(s,dp)<<endl;
    return 0;
}

// // greedy soltuion is also possible 
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     int count=0;
//     while (n!=0){
//         int k=n;
//         int ans=0;
//         while(k!=0){
//             ans=max(ans,k%10);
//             k=k/10;
//         }
//         n=n-ans;
//         count++;
//     }
//    cout<<count;
//     return 0;
// }