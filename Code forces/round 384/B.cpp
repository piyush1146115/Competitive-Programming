#include<bits/stdc++.h>
using namespace std;



int main()
{
   unsigned long long n, k, i, j, m;

   cin >> n >> k;

   m = pow(2, n);

   j = m;
   int ans;
   while(j >= 1){
    j /= 2;
    if(j == k){
        ans = n;
        break;
    }
    if(j < k){
        k -= j;
        //j = k;
    }
    n--;
   }
   cout << ans << endl;
}
