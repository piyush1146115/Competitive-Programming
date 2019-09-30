#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define ll long long

ll L[MAX], R[MAX], ara[MAX];

int main()
{
   ll n;
   cin >> n;

   for(int i = 1 ; i <= n; i++){
    cin >> ara[i];
   }
   L[0] = 0;
   ll gc = 0;

   for(int i = 1; i <= n; i++){
    L[i] = gc;
    gc = __gcd(ara[i], gc);
   }
   R[n + 1] = 0;
   gc = 0;
   for(int i = n + 1; i >= 1;i--){
    R[i] = gc;
    gc = __gcd(gc, ara[i]);
   }

   ll mx = 0;

   for(int i = 1; i <= n;i++){
    mx = max(mx, __gcd(L[i],R[i]));
   }



   cout << mx << endl;
}
