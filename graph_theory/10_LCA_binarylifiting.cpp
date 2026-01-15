#include<iostream>
using namespace std;
#include <bits/stdc++.h>
void dfs(vector<int>a[],vector<int>&parent,vector<int>&lebel,int node,int l,int par)
{
    parent[node]=par;
     lebel[node]=l;
     for(auto it:a[node])
     {
        if(lebel[it]==0)
        {
            dfs(a,parent,lebel,it,l+1,node);
        }
     }
}
int LCA_withoutbinarylifting(int u,int v,vector<int>&parent,vector<int>&lebel,int r)
{

 int i = u;
 int f = v;
    if(lebel[u] < lebel[v])
    {
       int temp = v;
       v = u;
       u = temp;
        
    }

    while(lebel[u]!=lebel[v])
    {
        u = parent[u];
 
    }
       if(u!=v)
       {
        while(u!=v)
        {
            u=parent[u];
            v=parent[v];
         
        }
       }
return v;
//  int c = v;
//  if((lebel[i] - lebel[c] )  >  r)
//  {
//     while(r--)
//     {
//         i = lebel[i];
//     }
//     return i;
//  }
//  else
//  {
//     r -= (lebel[i] - lebel[c] );
//     if(r >  (lebel[f] - lebel[c] ))
//     {
//         return f;
//     }
//     else{
//         r = (lebel[f] - lebel[c] ) -r;
//         while(r--)
//         {
//             lebel[f]=f;
//         }
//         return f;
//     }

//  }

     return v;
       
}
int main()
{
   int n;cin>>n;
   vector<int>a[n+1];
   for(int i=0;i<n-1;i++)
   {
    int x,y;
    cin>>x>>y;
       a[x].push_back(y);
       a[y].push_back(x);
   }
   vector<int>parent(n+1);
   vector<int>lebel(n+1,0);
   dfs(a,parent,lebel,1,1,1);


//    for(int i=0;i<n;i++)
//    {
//     cout<<parent[i]<<" "<<lebel[i]<<endl;
//    }

   int q;
   cin>>q;
   while(q--)
   {
    int r,s,t;
    cin>>r>>s>>t;
    cout<<LCA_withoutbinarylifting(r,s,parent,lebel,t)<<endl;
   }
}