#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Auto vector input
#define read_vec(name, size) vector<ll> name(size); for(int i = 0; i < size; i++) cin >> name[i];

// Auto vector output
#define print_vec(v) for (auto &x : v) cout << x << " "; cout << "\n";

int dfs(int node,int parent[],int level[])
{
   
    if(parent[node]==node)
    {

        return level[node] =0;
    }
    if(level[node]!=-1)
    {
        return level[node];
    }

    return level[node]=1+dfs(parent[node],parent,level);

    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t =1;

    while (t--) {

        int n;cin>>n;
        int parent[2*n+2];
        int level[2*n+2];
        for(int i=1;i<=(2*n)+1;i++)
        {
            parent[i]=i;
            level[i]=-1;
        }
        for(int i=1;i<=n;i++)
        {
            
            int x;
            cin>>x;
            
            parent[2*i]=x;
            parent[(2*i)+1]=x;
            

        }
        for(int i=1;i<=2*n+1;i++)
         {
             if(level[i]==-1)
             {
                dfs(i,parent,level);
             }
         }        

            for(int i=1;i<=2*n+1;i++)
         {
             cout<<level[i]<<endl;
         }        


    }

    return 0;
}