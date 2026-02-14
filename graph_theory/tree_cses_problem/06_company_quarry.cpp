#include <bits/stdc++.h>
using namespace std;
 
class BinaryLifting {
    vector<vector<int>> parent;
    int LOG;
 
public:
    BinaryLifting(vector<int>& p, int n) {
        LOG = ceil(log2(n + 1));
        parent.assign(LOG, vector<int>(n + 1, -1));
 
        for (int i = 1; i <= n; i++) {
            parent[0][i] = p[i];
        }
 
        for (int i = 1; i < LOG; i++) {
            for (int v = 1; v <= n; v++) {
                if (parent[i - 1][v] != -1)
                    parent[i][v] = parent[i - 1][ parent[i - 1][v] ];
            }
        }
    }
 
    int query(int node, int k) {
        for (int i = 0; i < LOG; i++) {
            if (node == -1) return -1;
            if (k & (1 << i)) {
                node = parent[i][node];
            }
        }
        return node;
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    t = 1;
 
    while (t--) {
        int n, q;
        cin >> n >> q;
 
        vector<int> p(n + 1, -1);
        for (int i = 2; i <= n; i++) {
            cin >> p[i];
        }
 
        BinaryLifting bl(p, n);
 
        while (q--) {
            int x, y;
            cin >> x >> y;
            cout << bl.query(x, y) << '\n';
        }
    }
    return 0;
}
