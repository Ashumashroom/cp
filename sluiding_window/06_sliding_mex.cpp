#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    unordered_map<int, int> freq;
    set<int> missing;

    // MEX can only be in range [0, k]
    for (int i = 0; i <= k; ++i)
        missing.insert(i);

    // Initialize first window
    for (int i = 0; i < k; ++i) {
        freq[a[i]]++;
        if (missing.count(a[i]))
            missing.erase(a[i]);
    }

    vector<int> ans;
    ans.push_back(*missing.begin());  // first window MEX

    // Slide window
    for (int i = k; i < n; ++i) {
        int add = a[i];
        int rem = a[i - k];

        // remove outgoing element
        freq[rem]--;
        if (freq[rem] == 0 && rem <= k)
            missing.insert(rem);

        // add new element
        freq[add]++;
        if (add <= k && missing.count(add))
            missing.erase(add);

        ans.push_back(*missing.begin());
    }

    // Output results
    for (int x : ans)
        cout << x << " ";
    cout << "\n";

    return 0;
}
