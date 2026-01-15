// !n = (n-1)(!n-1+!(n-2));
// !0=1;
// !1=1;
#include <iostream>      // for cin, cout
#include <vector>        // for vector
#include <map>           // for map
#include <set>           // for set
#include <algorithm>     // for sort, min, max, etc.
#include <climits>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
int fun(int n)
{
  ll n1 =1 ;
  ll n2 =1 ;
  if(n==0)return 1;
   if(n==1)return 1;
   for(int i=2;i<=n;i++)
   {
    ll ans = n1;
      n1 = ((i-1)*(n1+n2)) % NOD;
      n2 = ans;
   }
   return n1;
}

int main()
{
    int n;cin>>n;
    cout<<fun(n)<<endl;
}