#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

long long modpow(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    long long ans = 1;      // number of divisors
    long long res = 1;      // sum of divisors
    long long prod_div = 1; // product helper (will store N)

    for (int i = 0; i < t; i++) {
        long long n, k;
        cin >> n >> k;

        // number of divisors
        ans = (ans * ((k + 1) % mod)) % mod;

        // sum of divisors part
        long long numerator = (modpow(n, k + 1, mod) - 1 + mod) % mod;
        long long denominator = (n - 1 + mod) % mod;
        long long inv = modinv(denominator, mod);
        res = res * (numerator * inv % mod) % mod;

        // store N = product of p^k
        prod_div = (prod_div * modpow(n, k, mod)) % mod;
    }

    cout << ans << "\n";
    cout << res << "\n";

    // product of divisors = N^(number_of_divisors / 2)
    long long exp_half;
    if (ans % 2 == 0)
        exp_half = ans / 2;
    else
        exp_half = (ans + (mod - 1)) / 2; // safe divide by 2 mod (mod-1)

    long long prod = modpow(prod_div, exp_half, mod);
    cout << prod % mod << "\n";
}
