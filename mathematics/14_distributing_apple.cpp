#include <iostream>      // for cin, cout
#include <vector>        // for vector
#include <map>           // for map
#include <set>           // for set
#include <algorithm>     // for sort, min, max, etc.
#include <climits>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAXN = (1e6)*2;  
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
       
    }
}

int main()
{
   int n,m;
   cin>>n>>m;
   
    
    
    fun();
    int num = fac[n+m-1];
    
   long long int deno = 1;
 deno = fac(m);
   
    deno = modpow(deno,MOD -2);
    
    cout<<(deno*num)%MOD<<endl;

}