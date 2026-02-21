#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Auto vector input
#define read_vec(name, size) vector<ll> name(size); for(int i = 0; i < size; i++) cin >> name[i];

// Auto vector output
#define print_vec(v) for (auto &x : v) cout << x << " "; cout << "\n";


class binary_lifiting{
    vector<vector<int>>parent;
    int log = 31;
    public: 
      binary_lifiting(vector<int>&p ,int n)
      {
        parent.assign(log,vector<int>(n+1,-1));
        for(int i=1;i<=n;i++)
        {
           parent[0][i]=p[i];
        }

        for(int i=1;i<log;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(parent[i-1][j]!=-1)
                parent[i][j]=parent[i-1][parent[i-1][j]];
            }
        }

      }

      int query(int u,int k)
      {
        for(int i=0;i<log;i++)
        {
            if(u == -1)break;
            if(k&(1<<i))
            {
                u = parent[i][u];
            }
        }
        return u;
      }



};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
     t =1;

    while (t--) {

     int n,m;
     cin>>n>>m;
     vector<int>parent(n+1);
     parent[0]=-1;
     for(int i=1;i<=n;i++)
     {
        cin>>parent[i];
     }
     binary_lifiting ashish = binary_lifiting(parent,n);
     while(m--)
     {
        int x ,y;
        cin>>x>>y;
        cout<<ashish.query(x,y)<<endl;
     }


    }

    return 0;
}