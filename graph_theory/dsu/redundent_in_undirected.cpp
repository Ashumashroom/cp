class Solution {
public:

vector<int> size, parent;

int findpar(int v)
{
    if (parent[v] == v) return v;
    return parent[v] = findpar(parent[v]);
}

bool unionBySize(int u, int v)
{
    int up = findpar(u);
    int vp = findpar(v);

    if (up == vp) return false; // cycle

    if (size[up] < size[vp])
    {
        parent[up] = vp;
        size[vp] += size[up];
    }
    else
    {
        parent[vp] = up;
        size[up] += size[vp];
    }
    return true;
}

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

    int n = edges.size();

    vector<int> par(n+1,0);
    vector<int> cand1, cand2;

    // STEP 1 — detect 2 parent
    for(auto &e:edges)
    {
        int u=e[0], v=e[1];

        if(par[v]==0) par[v]=u;
        else
        {
            cand1 = {par[v],v};
            cand2 = e;
            e[1]=0;          // invalidate second edge
        }
    }

    // STEP 2 — DSU
    parent.resize(n+1);
    size.assign(n+1,1);

    for(int i=0;i<=n;i++) parent[i]=i;

    for(auto &e:edges)
    {
        if(e[1]==0) continue;

        int u=e[0], v=e[1];

        if(!unionBySize(u,v))
        {
            if(cand1.empty()) return e;
            return cand1;
        }
    }

    // STEP 3
    return cand2;
}
};