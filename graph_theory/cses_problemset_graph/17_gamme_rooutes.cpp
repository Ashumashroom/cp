
#include <iostream>
#include <vector>
using namespace std;
 
const long long MOD = 1000000007;
 
long long dfs(vector<long long>& dp, vector<long long> a[], long long node, long long n)
{
    if(dp[node] != -1)
        return dp[node];
    if(node == n) 
        return 1;
 
    long long ans = 0;
    for(auto it : a[node])
    {
        ans = (ans + dfs(dp, a, it, n)) % MOD; // modulo after each addition
    }
    return dp[node] = ans;
}
 
int main()
{
    long long n, edges;
    cin >> n >> edges;
 
    vector<long long> a[n + 1];
    for(long long i = 0; i < edges; i++)
    {
        long long x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
 
    vector<long long> dp(n + 1, -1);
    cout << dfs(dp, a, 1, n) << endl;
}