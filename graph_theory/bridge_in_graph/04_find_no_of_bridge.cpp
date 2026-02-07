#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// n(4alpha)//complexity

// Auto vector input
#define read_vec(name, size) vector<ll> name(size); for(int i = 0; i < size; i++) cin >> name[i];

// Auto vector output
#define print_vec(v) for (auto &x : v) cout << x << " "; cout << "\n";
class DisjointSet {
public:
    vector<int> parent, rankv, size;
    int components;
    int maxSize;

    DisjointSet(int n) {
        parent.resize(n + 1);
        rankv.resize(n + 1, 0);
        size.resize(n + 1, 1);

        components = n;
        maxSize = 1;

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); // path compression
    }

    // UNION BY RANK
    void unionByRank(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        if (rankv[pu] < rankv[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
            maxSize = max(maxSize, size[pv]);
        }
        else if (rankv[pv] < rankv[pu]) {
            parent[pv] = pu;
            size[pu] += size[pv];
            maxSize = max(maxSize, size[pu]);
        }
        else {
            parent[pv] = pu;
            rankv[pu]++;
            size[pu] += size[pv];
            maxSize = max(maxSize, size[pu]);
        }

        components--;
    }

    // UNION BY SIZE (preferred in practice)
    void unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
            maxSize = max(maxSize, size[pv]);
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
            maxSize = max(maxSize, size[pu]);
        }

        components--;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t= 1; // number of testcases

    while (t--) {
   int n,m;
   cin>>n>>m;
       vector<pair<int,int>>graph;
       for(int i=0;i<m;i++)
       {
          int a,b;
          cin>>a>>b;
          graph.push_back({a,b});    
       }
       int cnt = 0;
       for(int i=0;i<m;i++)
       {
        DisjointSet ashish = DisjointSet(n);
          for(int j=0;j<m;j++)
          {
            if(i!=j)
            {
                ashish.unionByRank(graph[j].first,graph[j].second);
                // cout<<graph[j].first<<" "<<graph[j].second<<endl;
            }
          }
      if(ashish.components > 1)
      {
        cnt++;
        // cout<<"comp"<<ashish.components<<endl;
      }

       }
      
cout<<cnt<<endl;
    }

    return 0;
}