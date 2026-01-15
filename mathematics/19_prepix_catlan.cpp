#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAXN = 2 * 1000000;

vector<ll> fact(MAXN + 1), invFact(MAXN + 1);

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
    fact[0] = 1;
    for (int i = 1; i <= MAXN; ++i) fact[i] = fact[i - 1] * i % MOD;
    invFact[MAXN] = modpow(fact[MAXN], MOD - 2);
    for (int i = MAXN; i >= 1; --i) invFact[i - 1] = invFact[i] * i % MOD;
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int n;
    string s;
    cin >> n >> s;

    int k = s.size();
    int open = 0, close = 0;
    bool invalid = false;
    for (char c : s) {
        if (c == '(') open++;
        else close++;
        if (close > open) invalid = true;
    }

    if (invalid || n % 2) {
        cout << 0 << endl;
        return 0;
    }

    int total_pairs = n / 2;
    int rem_open = total_pairs - open;
    int rem_close = total_pairs - close;

    if (rem_open < 0 || rem_close < 0) {
        cout << 0 << endl;
        return 0;
    }

    // Ballot number formula:
    // ans = ((u - d + 1) / (u + 1)) * C(u + d, d)
    int u = rem_open, d = rem_close;

    ll numerator = (u - d + 1 + MOD) % MOD;
    ll denominator = (u + 1) % MOD;
    ll comb = nCr(u + d, d);

    ll ans = comb * numerator % MOD * modpow(denominator, MOD - 2) % MOD;
    cout << ans % MOD << endl;
}
