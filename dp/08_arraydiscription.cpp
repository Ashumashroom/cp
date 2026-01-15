#include <iostream>
#include <vector>
using namespace std;
 
const long long MOD = 1e9 + 7;
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
 
    // dp[i][x] → ways for prefix ending at index i with value x
    vector<vector<long long>> dp(n, vector<long long>(m + 2, 0));
 
    // Base case (i = 0)
    if (a[0] == 0) {
        for (int x = 1; x <= m; x++) dp[0][x] = 1;
    } else {
        dp[0][a[0]] = 1;
    }
 
    // Fill DP table
    for (int i = 1; i < n; i++) {
        if (a[i] != 0) {
            int x = a[i];
            // sum from previous possible values x-1, x, x+1
            for (int d = -1; d <= 1; d++) {
                int prev = x + d;
                if (prev >= 1 && prev <= m)
                    dp[i][x] = (dp[i][x] + dp[i - 1][prev]) % MOD;
            }
        } else {
            for (int x = 1; x <= m; x++) {
                for (int d = -1; d <= 1; d++) {
                    int prev = x + d;
                    if (prev >= 1 && prev <= m)
                        dp[i][x] = (dp[i][x] + dp[i - 1][prev]) % MOD;
                }
            }
        }
    }
 
    // Sum all valid ways for last position
    long long ans = 0;
    for (int x = 1; x <= m; x++) {
        ans = (ans + dp[n - 1][x]) % MOD;
    }
 
    cout << ans << endl;
    return 0;
}