#include <bits/stdc++.h>
using namespace std;
 
// set<int>st;
// void fun(int index ,int sum,int n,vector<int> &nums)
// {
   
//     if(index == n)
//     {
//          st.insert(sum); return ;
//     }
   
//     fun(index +1 ,sum+nums[index],n,nums);
//     fun(index+1,sum,n,nums);
//     return;
    
// }
int main()
{
 
   int n;cin>>n;
   vector<int>a(n);
   for(int i=0;i<n;i++)
   {
    cin>>a[i];
   }

   int sum = accumulate(a.begin(),a.end(),0);
    vector<bool>dp(sum+1,false);
    dp[0]=true;
    int max_sum = 0;
    for(int j=0;j<n;j++)
    {
        for(int i= sum ;i>=1;i--)
        {
            if(i - a[j]>=0)
            {
                dp[i]=(dp[i]|| dp[i - a[j]]);
            }
        }


    }
    for(int i=1;i<=sum;i++)
    {
        if(dp[i])max_sum++;
    }
    cout<<max_sum<<endl;
    for(int i=1;i<=sum;i++)
    {
        if(dp[i])cout<<i<<" ";
    }

 
}
