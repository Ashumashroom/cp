#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
#include<set>
using namespace std;
const int mod = 1e9+7;

  int main()
    {
        int t;cin>>t;while(t--){
       long long  int x,y;
        cin>>x>>y;
       long long int result =1 ;
       while(y)
       {
           if(y%2)
           {
             result*=x;
             result = result%mod;
           }
          x*=x;
          x= x%mod;
         y = y/2;
       }
       cout<<result<<endl;
    }
}