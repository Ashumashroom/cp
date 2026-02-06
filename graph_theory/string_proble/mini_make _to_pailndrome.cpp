#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Auto vector input
#define read_vec(name, size) vector<ll> name(size); for(int i = 0; i < size; i++) cin >> name[i];

// Auto vector output
#define print_vec(v) for (auto &x : v) cout << x << " "; cout << "\n";
vector<int>pp;
vector<int>sizzz;
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
    void funn()
    {
        pp = parent ;
    }
    void funn2()
    {
        sizzz = size ;
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
    // number of testcases
    t=1;

    while (t--) {

      int n;cin>>n;
      int s[n];
      for(int i=0;i<n;i++)
      {
        cin>>s[i];

      }
      int l =0;
      int sz = n/2;
      DisjointSet ashish = DisjointSet(200000+2);
      set<int>st;
      for(int i=0;i < sz ;i++)
      {
          if(s[i]!=s[n-1-i])
          {
               ashish.unionBySize(s[i],s[n-i-1]);
            // st.insert(s[i]);
            // st.insert(s[n-1-i]);
          }
      }
ashish.funn();
ashish.funn2();
int ans =0;
      for(int i=1;i<200000+2;i++)
      {
         if(pp[i]==i)
         {
            ans+=(sizzz[ashish.find(i)] -1);
         }
      }
      cout<<ans<<endl;
    }

    return 0;
}