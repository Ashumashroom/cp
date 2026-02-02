#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Auto vector input
#define read_vec(name, size) vector<ll> name(size); for(int i = 0; i < size; i++) cin >> name[i];

// Auto vector output
#define print_vec(v) for (auto &x : v) cout << x << " "; cout << "\n";
ll dp[20][2][10];
string s;
ll fun(int index,bool tight,int adj_val)
{
    if(index==s.size())
    {
        return 1;
    }
    if(adj_val!=-1)
    {
    if(dp[index][tight][adj_val]!=-1)return dp[index][tight][adj_val];
    }
    ll l =0;
    ll ul = tight?(s[index]-'0'):9;
    ll ans =0;
    for(int i=0;i<=ul;i++)
    {
        res+=(fun(index+1,(tight && s[index]!=adj_val),s[index]));
    }
    return dp[index][tight][adj_val] =res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    // number of testcases
    t=1;


    while (t--) {

       int l,r;
       cin>>l>>r;
       s = to_string(r);
       memset(dp,-1,sizeof(dp));
       ll a = fun(0,1,-1);
       s = to_string(l-1);
       memset(dp,-1,sizeof(dp));
       ll b = fun(0,1,-1);
       cout<<a - b <<endl;



       
    }

    return 0;
}