#include <iostream>      // for cin, cout
#include <vector>        // for vector
#include <map>           // for map
#include <set>           // for set
#include <algorithm>     // for sort, min, max, etc.
#include <climits>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1000000;
int main()
{
   long long int n,k;
    cin>>n>>k;
    long long int x,a,b,c;
    cin>>x>>a>>b>>c;
    long long int ans = 0;
    long long int sum =x;
   long long int prev = x;
    for(int i=1;i<k;i++)
    {
    
       prev =(a*prev+b)%c;
           
       sum+=prev;
    }
    // cout<<sum<<endl;
    int prev2 = x;
    for(int i=k;i<=n;i++)
    {
        ans^=sum;
        sum = sum - prev2;
         prev =(a*prev+b)%c;
           
       sum+=prev;
          prev2 = ((a*prev2+b)%c);
    }
    cout<<ans;
}