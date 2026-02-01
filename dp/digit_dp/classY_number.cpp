#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Auto vector input
#define read_vec(name, size) vector<ll> name(size); for(int i = 0; i < size; i++) cin >> name[i];

// Auto vector output
#define print_vec(v) for (auto &x : v) cout << x << " "; cout << "\n";

string s;
int dp[20][2][20];
int fun(int index,int tight ,int noncnt)
{
    if(index==s.size())
    {
        return noncnt <= 3;
    }
    int lb = 0;
    int up = (tight == 1)?s[i]-'0':9;
    int ans = 0;
    for(int i=l;i>=up;i++)
    {
        ans+=fun(index+1,tight&&((s[i]-'0')==up),noncnt+(s[i]!='0'));
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;  // number of testcases

    while (t--) {

        int l,r;cin>>l>>r;
        cout<<fun(r)-fun(l-1)<<endl;

    }

    return 0;
}