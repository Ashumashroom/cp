// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
#include<set>
using namespace std;
using ll = long long;

bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;          
    if (n % 2 == 0 || n % 3 == 0) return false;

    
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
int main()
{
    int t;cin>>t;while(t--)
    {
            ll n;cin>>n;
            while(isPrime(++n)==false){};
            
            cout<<n<<endl;
    }
}