#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAXN = 2 * 1000000; // supports n up to 1e6 pairs

vector<ll> fac(MAXN + 1);

ll modpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; ++i)
        fac[i] = fac[i - 1] * i % MOD;
}

int main() {
    int n, m; // m unused, but kept for consistency with your code
    cin >> n >> m;

    if (n % 2) {
        cout << 0 << endl;
        return 0;
    }

    precompute();
    int k = n / 2;

    ll numerator = fac[n]; // (2k)!
    ll denominator = (fac[k] * fac[k]) % MOD; // (k!)^2
    denominator = (denominator * (k + 1)) % MOD; // multiply by (k+1)

    ll ans = numerator * modpow(denominator, MOD - 2) % MOD;
    cout << ans << endl;
}
