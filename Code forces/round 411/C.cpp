#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin >> n;

    ll ans = (n/2) + ( n % 2) - 1;

    cout << ans << endl;
}
