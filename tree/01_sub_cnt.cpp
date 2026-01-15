#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <utility>
#include <limits>
#include <iomanip>
#include <functional>

using namespace std;

int fun(vector<vector<int>>&graph,vector<int>&ans,int node)
{
   int tt = 0;
  
   for(auto it: graph[node])
   {
    
       tt += (1 + fun(graph,ans,it));
   }

  return ans[node]=tt;
}
   int main()
   {
       int n;cin>>n;
       int a[n];
       for(int i=0;i<n-1;i++)
       {
        cin>>a[i];
       }
       vector<vector<int>>graph(n+1);
       for(int i=0;i<n-1;i++)
       {
        graph[a[i]].push_back(i+2);
       }
     
       
       vector<int>ans(n+1,-1);
       fun(graph,ans,1);

       for(int i=1;i<=n;i++)
       {
        cout<<ans[i]<<" ";
       }
       cout<<endl;
   }