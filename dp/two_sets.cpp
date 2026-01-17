#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Auto vector input
#define read_vec(name, size) vector<ll> name(size); for(int i = 0; i < size; i++) cin >> name[i];

// Auto vector output
#define print_vec(v) for (auto &x : v) cout << x << " "; cout << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    t =1;

    while (t--) {
    ll n;
    cin>>n;
    ll sum = n*(n+1)/2;
    if(sum%2!=0)
    {
       cout<<0<<"\n";
    }
    else
    {
        sum=sum/2;
        vector<ll> dp(sum+1,0);
        dp[0]=1;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=sum;j>=0;j--)
            {
                if(j-i>=0)
                {
                    dp[j]=(dp[j]+dp[j-i])%1000000007;
                }
            }
        }

    const ll MOD = 1000000007;
ll inv2 = (MOD + 1) / 2;
cout << (dp[sum] * inv2) % MOD << "\n";

    }

    }

    return 0;
}