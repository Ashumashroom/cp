#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
       int a;
       cin>>a;
       set<int>st;
       for(int i=1;i*i<=a;i++)
       {
        if(a%i==0)
        {
         st.insert(i);
         st.insert(a/i);
        }
       }
       cout<<st.size()<<endl;
    }
}
// #include <bits/stdc++.h>
// using namespace std;

// const int MAXN = 1e6;
// int divCount[MAXN + 1];

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // Precompute divisor counts for all numbers up to 1e6
//     for (int i = 1; i <= MAXN; i++) {
//         for (int j = i; j <= MAXN; j += i) {
//             divCount[j]++;
//         }
//     }

//     int n;
//     cin >> n;
//     while (n--) {
//         int x;
//         cin >> x;
//         cout << divCount[x] << "\n";
//     }

//     return 0;
// }
