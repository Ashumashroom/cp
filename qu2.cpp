echo 'alias g++=/opt/homebrew/bin/g++-15' >> ~/.zshrc
source ~/.zshrc
g++ hlo1.cpp -o hlo1
./hlo1 < input.txt > output.txt

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }


    set<pair<int,pair<int,int>>> st;

    vector<vector<int>> indegree(n,vector<int>(m,0));

    vector<pair<int,int>> dir={{0,1},{1,0},{-1,0},{0,-1}};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] != '.') continue;

            for(auto d: dir){
                int x=i+d.first;
                int y=j+d.second;

                if(x>=0 && x<n && y>=0 && y<m){
                    if(grid[x][y]=='.'){
                        indegree[i][j]++;
                    }
                }
            }

            st.insert({indegree[i][j],{i,j}});
        }
    }
    // vector<vector<int>>vis(n,vector<int>m(0,))

    while(!st.empty() && k>0){
        auto it = *st.begin();  
        st.erase(st.begin());

        int ind = it.first;
        int x = it.second.first;
        int y = it.second.second;

        if(grid[x][y] != '.') continue;

        grid[x][y]='X';
        k--;

        for(auto d: dir){
            int nx=x+d.first;
            int ny=y+d.second;

            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(grid[nx][ny]=='.'){
                    st.erase({indegree[nx][ny],{nx,ny}});
                    indegree[nx][ny]--;
                    st.insert({indegree[nx][ny],{nx,ny}});
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}