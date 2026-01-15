#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAXN = 1e6;  // maximum a

vector<ll> fact(MAXN + 1), invFact(MAXN + 1);

// Fast modular exponentiation
ll modpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// Precompute factorials and inverse factorials
void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[MAXN] = modpow(fact[MAXN], MOD - 2); // Fermat inverse
    for (int i = MAXN - 1; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

// Compute C(a, b) % MOD
ll nCr(int a, int b) {
    if (b < 0 || b > a) return 0;
    return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << nCr(a, b) << "\n";
    }
}


// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// const int mod = 1e9 + 7;

// ll modpow(ll a, ll b, ll m) {
//     ll res = 1;
//     while (b) {
//         if (b & 1) res = res * a % m;
//         a = a * a % m;
//         b >>= 1;
//     }
//     return res;
// }

// ll modInverse(ll a, ll m) {
//     // Fermat's little theorem: a^(m-2) ≡ a^(-1) (mod m)
//     return modpow(a, m - 2, m);
// }

// ll binomial(int n, int r) {
//     if (r < 0 || r > n) return 0;
//     r = min(r, n - r);
//     ll num = 1, den = 1;

//     for (int i = 0; i < r; i++) {
//         num = num * (n - i) % mod;
//         den = den * (i + 1) % mod;
//     }

//     return num * modInverse(den, mod) % mod;
// }

// int main() {
//     int n, r;
//     cin >> n >> r;
//     cout << binomial(n, r) << "\n";
// }
