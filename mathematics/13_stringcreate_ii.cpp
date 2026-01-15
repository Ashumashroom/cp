#include <iostream>      // for cin, cout
#include <vector>        // for vector
#include <map>           // for map
#include <set>           // for set
#include <algorithm>     // for sort, min, max, etc.
#include <climits>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAXN = 1e6;  
vector<int>fac(MAXN+1);
ll modpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
void fun()
{
    fac[0]=1;
  long long  ans = 1;
    for(int i=1;i<=MAXN;i++)
    {
        ans =  (ans * i)%MOD;
        fac[i]= ans;
        // if(i<9)
        // cout<<fac[i]<<endl;
    }
}

int main()
{
    string s ;
    cin>>s;
    int n = s.size();
    int a[26]={0};
    for ( int i = 0; i < n; i++)
    {
       a[s[i]-'a']++;
    }
    // cout<<a[0]<<endl;
    fun();
    int num = fac[n];
    // cout<<num<<endl;
   long long int deno = 1;
    for(int i=0;i<26;i++)
    {
        deno = (deno*fac[a[i]])%MOD;
    }
    // cout<<deno<<endl;
    deno = modpow(deno,MOD -2);
    // cout<<deno<<endl;
    cout<<(deno*num)%MOD<<endl;

}