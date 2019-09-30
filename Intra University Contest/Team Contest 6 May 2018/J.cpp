#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll row, col;

   while(cin >> row >> col){
    ll n = row + col -1;

    ll s = (n * (n + 1))/2;
    ll ans;
    if(n % 2 == 0){
        ans = (s - (n - row));
    }
    else{
        ans = s - (row - 1);
    }

    cout << ans << endl;
   }
}
