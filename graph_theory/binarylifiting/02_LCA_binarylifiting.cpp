#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> up;

void dfs(vector<int>a[], vector<int>&parent, vector<int>&lebel, int node, int l, int par)
{
    parent[node] = par;
    lebel[node] = l;
    for (auto it : a[node])
    {
        if (lebel[it] == 0)
        {
            dfs(a, parent, lebel, it, l + 1, node);
        }
    }
}

void binary_lifting(int n, vector<int>&parent)
{
    int LOG = 20;
    up.assign(LOG, vector<int>(n+1, 0));

    for (int v = 1; v <= n; v++)
        up[0][v] = parent[v];

    for (int i = 1; i < LOG; i++)
    {
        for (int v = 1; v <= n; v++)
        {
            if (up[i-1][v] != 0)
                up[i][v] = up[i-1][up[i-1][v]];
        }
    }
}

int jump(int node, int k)
{
    int LOG = 20;
    for (int i = 0; i < LOG; i++)
    {
        if (k & (1 << i))
        {
            node = up[i][node];
            if (node == 0) return 0;
        }
    }
    return node;
}

int common_ancestor(int u, int v, vector<int>&parent, vector<int>&lebel)
{
    if (lebel[u] < lebel[v]) swap(u,v);

    int k = lebel[u] - lebel[v];
    u = jump(u,k);
    if (u == v) return u;

    for (int i=19; i>=0; i--)
    {
        if (up[i][u] != up[i][v])
        {
            u = up[i][u];
            v = up[i][v];
        }
    }
    return parent[u];
}

int LCA_withoutbinarylifting(int u,int v,vector<int>&parent,vector<int>&lebel,int r)
{
    int c = common_ancestor(u,v,parent,lebel);

    int distU = lebel[u] - lebel[c];
    int distV = lebel[v] - lebel[c];

    if (r <= distU)
        return jump(u, r);
    r -= distU;

    if (r <= distV)
        return jump(v, distV - r);

    return v; // if r is too large, just return v
}

int main()
{
    int n; cin >> n;
    vector<int>a[n+1];
    for (int i=0; i<n-1; i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    vector<int>parent(n+1), lebel(n+1,0);
    dfs(a,parent,lebel,1,1,0); // root parent = 0

    binary_lifting(n,parent);

    int q; cin >> q;
    while (q--)
    {
        int r,s,t;
        cin >> r >> s >> t;
        cout << LCA_withoutbinarylifting(r,s,parent,lebel,t) << "\n";
    }
}
