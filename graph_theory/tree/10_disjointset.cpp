#include <iostream>      // for cin, cout
#include <vector>        // for vector
#include <map>           // for map
#include <set>           // for set
#include <algorithm>     // for sort, min, max, etc.
#include <climits> 
using namespace std;
class DisjointSet {
   
       vector<int> parent,rank ,size ;
       public: 
         DisjointSet(int n)
         {
            parent.assign(n+1,0);
            rank.assign(n+1,0);
            size.assign(n+1,1);
            for(int i=0;i<=n;i++)
            {
                parent[i]=i;
            }
         }
        
        int findUPar(int node)
        {
            if(node==parent[node])
            {
                return node;
            }
            return parent[node]=findUPar(parent[node]);
        }

        void unionByrank(int u ,int v)
        {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u==ulp_v) return;
            if(rank[ulp_u]<rank[ulp_v])
            {
                parent[ulp_u]=ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u])
            {
                parent[ulp_v]=ulp_u;
            }
            else{
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBysize(int u ,int v)
        {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u==ulp_v) return;
            if(size[ulp_u]<size[ulp_v])
            {
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
    };