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


int final_ans = 0;
vector<int>r1;
vector<int>r2;
int bfs(vector<vector<int>>&adj,int node)
{
    vector<bool> visited(adj.size(), false);
    queue<int>q;
    q.push(node);
    visited[node]=true;
   


    int ans = node;
    while(!q.empty())
    {
        auto ind = q.front();
        ans = ind;
        for(auto it:adj[ind])
        {
            if(!visited[it])
            {
               q.push(it);
               visited[it]=true;
               
            }
        }
        q.pop();
    }
    return ans ;

}

void bfs2(vector<vector<int>>&adj,int node,vector<int>&dis)
{
    vector<bool> visited(adj.size(), false);
    queue<int>q;
    q.push(node);
    visited[node]=true;
     dis[node]=0;

    int ans = node;
    while(!q.empty())
    {
        auto ind = q.front();
        ans = ind;
        for(auto it:adj[ind])
        {
            if(!visited[it])
            {
               q.push(it);
               visited[it]=true;
               dis[it]=1+dis[ind];
            }
        }
        q.pop();
    }
    return ;

}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int xx = bfs(adj,1);
    int yy = bfs(adj,xx);
    r1.assign(n+1,0);
    r2.assign(n+1,0);
    bfs2(adj,xx,r1);
    bfs2(adj,yy,r2);
    for(int i=1;i<=n;i++)

    {
        cout<<max(r1[i],r2[i])<<" ";
    }
    cout<<endl;

    return 0;
}
