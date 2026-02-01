#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
ll dp[20][2][4];

ll fun(int index, int tight, int noncnt)
{
    if (noncnt > 3) return 0;

    if (index == (int)s.size())
        return 1;  // valid because noncnt <= 3 guaranteed

    ll &res = dp[index][tight][noncnt];
    if (res != -1) return res;

    int up = tight ? (s[index] - '0') : 9;
    ll ans = 0;

    for (int dig = 0; dig <= up; dig++)
    {
        ans += fun(
            index + 1,
            tight && (dig == up),
            noncnt + (dig != 0)
        );
    }

    return res = ans;
}

ll solve(ll x)
{
    if (x < 0) return 0;
    s = to_string(x);
    memset(dp, -1, sizeof(dp));
    return fun(0, 1, 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        cout << solve(r) - solve(l - 1) << '\n';
    }
    return 0;
}