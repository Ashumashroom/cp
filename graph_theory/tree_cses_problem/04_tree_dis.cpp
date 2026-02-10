#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;  // n nodes, m edges

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);  // remove if graph is directed
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