#include <bits/stdc++.h>
using namespace std;

class TreeAncestor {
    int LOG;
    vector<vector<int>> up; // up[i][v] = 2^i-th ancestor of v
public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 20; // enough for n <= 5e4
        up.assign(LOG, vector<int>(n+1, 0));

        // Initialize 2^0 (direct parent)
        for (int v = 1; v <= n; v++) {
            up[0][v] = parent[v];
        }

        // Build binary lifting table
        for (int i = 1; i < LOG; i++) {
            for (int v = 1; v <= n; v++) {
                if (up[i-1][v] != -1) {
                    up[i][v] = up[i-1][up[i-1][v]];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0; i < LOG; i++) {
            if (k & (1 << i)) {
                node = up[i][node];
                if (node == 0) return 0; // no ancestor exists
            }
        }
        return node;
    }
};

int main() {
 int n,q;
 cin>>n>>q;
 vector<int>parent(n+1,0);
 for(int i=1;i<=n;i++)
 {
    int x;cin>>x;
    parent[i]=x;
 }

    TreeAncestor tree(n, parent);

while(q--)
{
    int x, y;
    cin>>x>>y;
    cout<<getKthAncestor(x,y)<<endl;

}
    return 0;
}
