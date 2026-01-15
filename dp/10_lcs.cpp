#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fun(const vector<int> &s, const vector<int> &t, int i, int j, vector<vector<int>>& dp) {
    if (i == s.size() || j == t.size()) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == t[j]) 
        return dp[i][j] = 1 + fun(s, t, i + 1, j + 1, dp);
    else
        return dp[i][j] = max(fun(s, t, i + 1, j, dp), fun(s, t, i, j + 1, dp));
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    int tt = fun(a, b, 0, 0, dp);
    cout << tt << endl;

    
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            ans.push_back(a[i]);
            i++; j++;
        } else if (i + 1 < n && dp[i + 1][j] >= dp[i][j + 1]) {
            i++;
        } else {
            j++;
        }
    }

    for (int x : ans) cout << x << " ";
    cout << endl;
}