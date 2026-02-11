#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Auto vector input
#define read_vec(name, size) vector<ll> name(size); for(int i = 0; i < size; i++) cin >> name[i];

// Auto vector output
#define print_vec(v) for (auto &x : v) cout << x << " "; cout << "\n";
class binary_lifiting{
    vector<vector<int>>parent;

    binary_lifiting(vector<int>p,int n)
    {
       parent.assign(n+1,vector<int>(12,0));
       p[1]=-1;
       for(int i=2;i<=n;i++)
       {
          parent[i][0]=p[i];
       }
       for(int i=1;i<12;i++)
       {
           for(int j=1;j<=n;j++)
           {
              parent[i][j]=parent[i-1][parent[i-1][j]];
           }
       }

    }

    int quarry(int node,int k)
    {
        for(int i=0;i<12;i++)
        {
            if((1<<i)&k)
            {
                 node = parent[i][node];
            }
            if(node == -1)return -1;
        }
        return node;
    }

}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;  // number of testcases

    while (t--) {

        int n, q;
        cin >> n >> q;  // pair input

    vector<int>p(n+1);
    for(int i=2;i<=n;i++)
    {
        cin>>p[i];
    }
    binary_lifiting ashish = binary_lifiting(p,n);
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<ashish.quarry(x,y);
    }

    }

    return 0;
}