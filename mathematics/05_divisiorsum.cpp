#include <bits/stdc++.h>
using namespace std;
const int mod =1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
       int a;
       cin>>a;
    
       int ans =0;
       for(int i=1;i*i<=a;i++)
       {
        if(a%i==0)
        {
         ans = (ans%mod + i%mod)%mod;
         ans =  (ans%mod + (a/i)%mod)%mod;
        }
       }
       return ans;
          
    }
}