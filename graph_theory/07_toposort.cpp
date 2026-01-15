#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
     vector<int>a[n];
     vector<int>indgree(n,0);
     for(int i=0;i<m;i++)
     {
        int x,y;
        cin>>x>>y;

        a[x].push_back(y);
        indgree[y]++;
     }
     queue<int>q;
     for(int i=0;i<n;i++)
     {
        if(indgree[i]==0)
        {
            q.push(i);
        }
     }
     vector<int>toposort;
     while(!q.empty())
     {
          auto node = q.front();
          q.pop();
          for(auto it:a[node])
          {
            indgree[it]--;
            if(indgree[it]==0)
            {
                q.push(it);
            }
          }
          toposort.push_back(node);
     }
     if(toposort.size() < n)
     {
        cout<<"IMPOSSIBLE"<<endl;
     }

     else{
        for(auto it: toposort)
        {
            cout<<it<<" ";
        }
        cout<<endl;
     }

    
}