#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Auto vector input
#define read_vec(name, size) vector<ll> name(size); for(int i = 0; i < size; i++) cin >> name[i];

// Auto vector output
#define print_vec(v) for (auto &x : v) cout << x << " "; cout << "\n";

int fun(int index,int set_bit )
{
    if(index == n) return 0;
    for(int i=0;i<n;i++)
    {
        if((1<<i)&(set_bit)==0)
        {
            ans = min((ans,index+1,))
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
   t= 1;


    while (t--) {
       int n,m;
       int grpah[n][m];
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            cin>>grpah[i][j];
        }
       }


    }

    return 0;
}