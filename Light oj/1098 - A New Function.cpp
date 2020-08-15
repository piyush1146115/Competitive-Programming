#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll SOD(ll n)
{
    ll cnt = 0;
    for(int i = 2; i < n; i++){
        if(n % i == 0)
            cnt += i;
    }

    return cnt;
}

int main()
{
  ll n;
  int test;

  scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++){
        scanf("%lld", &n);

        ll ans = 0;

        for(int i = 2; i <= n; i++){
            ans += SOD(i);
        }

        printf("Case %d: %lld\n",tc, ans);
    }
}
