#include <iostream>
#include <vector>
#include <queue>

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    vector<string>mat;
    for(int i=0;i<m;i++)
    {
        string s;
        cin>>s;
        mat.push_back(s);
    }

    vector<vector<int>>dis(m,vector<int>(n,0));
    queue<pair<int,int>>q;
    pair<int,int>start;
    pair<int,int>finish={-1,-1};

    // parent array to store previous cell
    vector<vector<pair<int,int>>>par(m, vector<pair<int,int>>(n, {-1,-1}));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]=='M')
            {
                dis[i][j]=1;
                q.push({i,j});
            }
            if(mat[i][j]=='A')
            {
                start = {i,j};
            }
        }
    }

    q.push(start);

    while(!q.empty())
    {
        auto node = q.front();
        q.pop();
        int x  = node.first;
        int y = node.second;

        // UP
        if(x-1 >=0 && mat[x-1][y]=='.')
        {
            mat[x-1][y] = (mat[x][y]=='M') ? 'M' : 'U';
            par[x-1][y] = {x,y};
            q.push({x-1,y});
            if(x-1 == 0 && mat[x-1][y]!='M') { finish={0,y}; break; }
        }
        // DOWN
        if(x+1 < m && mat[x+1][y]=='.')
        {
            mat[x+1][y] = (mat[x][y]=='M') ? 'M' : 'D';
            par[x+1][y] = {x,y};
            q.push({x+1,y});
            if(x+1 == m-1 && mat[x+1][y]!='M') { finish={m-1,y}; break; }
        }
        // LEFT
        if(y-1 >=0 && mat[x][y-1]=='.')
        {
            mat[x][y-1] = (mat[x][y]=='M') ? 'M' : 'L';
            par[x][y-1] = {x,y};
            q.push({x,y-1});
            if(y-1 == 0 && mat[x][y-1]!='M') { finish={x,0}; break; }
        }
        // RIGHT
        if(y+1 < n && mat[x][y+1]=='.')
        {
            mat[x][y+1] = (mat[x][y]=='M') ? 'M' : 'R';
            par[x][y+1] = {x,y};
            q.push({x,y+1});
            if(y+1 == n-1 && mat[x][y+1]!='M') { finish={x,n-1}; break; }
        }

        if(finish.first!=-1) break;
    }
if(start.first == 0 || start.first == m-1 || start.second == 0 || start.second == n-1) {
    cout << "YES\n0\n";
    return 0;
}

    if(finish.first==-1)
    {
        cout<<"NO"<<endl;
        return 0;
    }

    // Reconstruct path
    string path;
    int x = finish.first;
    int y = finish.second;
    while(x != start.first || y != start.second)
    {
        int px = par[x][y].first;
        int py = par[x][y].second;

        if(px == x-1) path.push_back('D'); // came from UP
        else if(px == x+1) path.push_back('U'); // came from DOWN
        else if(py == y-1) path.push_back('R'); // came from LEFT
        else if(py == y+1) path.push_back('L'); // came from RIGHT

        x = px;
        y = py;
    }

    reverse(path.begin(), path.end());

    cout<<"YES"<<endl;
    cout<<path.size()<<endl;
    cout<<path<<endl;

    return 0;
}
