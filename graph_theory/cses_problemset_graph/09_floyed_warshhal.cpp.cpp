#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m,q;
    cin >> n >> m >>q;  // n nodes, m edges

    vector<vector<ll>>mat(n+1,vector<ll>(n+1,INF));

    for (int i = 0; i < m; i++) {
        ll a, b,dis;
        cin >> a >> b>>dis;
       mat[a][b] = min(mat[a][b], dis);
        mat[b][a] = min(mat[b][a], dis);
         
    }
    for(int i=0;i<=n;i++)
    {
        mat[i][i]=0; 
    }
    //viapath
    for(int k=1;k<n+1;k++)
    {

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(mat[i][k]==INF||mat[k][j]==INF)
continue;
                  mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }

    }
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(mat[a][b] == INF)
        cout<<-1<<endl;
        else cout<<mat[a][b]<<endl;
    }



    return 0;
}

