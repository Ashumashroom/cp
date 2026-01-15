#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <utility>
#include <limits>
#include <iomanip>
#include <functional>

using namespace std;


int final_ans = 0;

int daimerer(vector<vector<int>>& adj, int n, vector<bool>& visited)
{
    visited[n] = true;
    vector<int> result; // <--- IMPORTANT FIX

    int ans = 0;

    for(auto it : adj[n])
    {
        if(!visited[it])
        {
            int mn = 1 + daimerer(adj, it, visited);
            result.push_back(mn);
            ans = max(ans, mn);
        }
    }

    sort(result.rbegin(), result.rend());

    if(result.size() >= 2)
    {
        final_ans = max(final_ans, result[0] + result[1]);
    }
    else if(result.size() == 1)
    {
        final_ans = max(final_ans, result[0]);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n+1, false);
    daimerer(adj, 1, visited);

    cout << final_ans << endl;
    return 0;
}
