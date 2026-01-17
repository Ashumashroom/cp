#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Auto vector input
#define read_vec(name, size) vector<ll> name(size); for(int i = 0; i < size; i++) cin >> name[i];

// Auto vector output
#define print_vec(v) for (auto &x : v) cout << x << " "; cout << "\n";


ll fun(vector<ll> &a, vector<ll> &b, int index,ll x,vector<vector<ll>> &dp0)
{
    if(index == a.size())
    {
        return 0;
    }
    if(dp0[index][x] != -1)
    {
        return dp0[index][x];
    }
    if(x)
    {
        return dp0[index][x] = max(a[index] + fun(a,b,index+1,0,dp0), fun(a,b,index+1,1,dp0));
    }
    else{
        return dp0[index][x] = max(b[index] + fun(a,b,index+1,1,dp0), fun(a,b,index+1,0,dp0));
    }
}

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//    t = 1;
//     while (t--) {

//         int n;cin>>n;
//         read_vec(a,n);
//         read_vec(b,n);
//         vector<vector<ll>> dp0(n,vector<ll>(2,-1));
//         vector<vector<ll>> dp1(n,vector<ll>(2,-1));
//         cout<<max(fun(a,b,0,1,dp0),fun(a,b,0,0,dp1))<<endl;


//     }

//     return 0;
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
   t = 1;
    while (t--) {

        int n;cin>>n;
        read_vec(a,n);
        read_vec(b,n);
        vector<vector<ll>> dp0(n,vector<ll>(2,0));
       
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
               
                    dp0[i][j]=max(a[i]+dp0[i+1][0],dp0[i+1][1]);
              
            }
        }
        cout<<max(dp0[0][0],dp0[0][1])<<endl;


    }

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;

//     vector<ll> a(n), b(n);
//     for (int i = 0; i < n; i++) cin >> a[i];
//     for (int i = 0; i < n; i++) cin >> b[i];

//     ll dpA = 0; // a allowed
//     ll dpB = 0; // b allowed

//     for (int i = 0; i < n; i++) {
//         ll new_dpA = max(dpA, dpB + b[i]);
//         ll new_dpB = max(dpB, dpA + a[i]);
//         dpA = new_dpA;
//         dpB = new_dpB;
//     }

//     cout << max(dpA, dpB) << "\n";
//     return 0;
// }
