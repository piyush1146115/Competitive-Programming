#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ara[60];
int main()
{
    ara[1] = 2;

    for(int i = 2; i <= 56; i++){
        ara[i] = 2 * ara[i - 1];
    }

    ll n, ans = 0;

    scanf("%lld",&n);

    for(int i = 1; i <= n; i++){
        ans += ara[i];
    }

    cout << ans << endl;
}
