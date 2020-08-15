#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[55][55];
ll power(ll a, ll b)
{
    if(b == 0)
        return 1ll;
    if(b % 2 == 0){
        ll ret = power(a, b/ 2);
        return (ret * ret);
    }
    else{
        return (a * power(a, b - 1));
    }
}

int main()
{
    ll n, m;

    scanf("%I64d %I64d", &n, &m);

      //  cout << n << " " << m << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%I64d", &ara[i][j]);
        }
    }

    ll ans = m * n;
    for(ll i = 0; i < n; i++){
        ll x = 0, y = 0;
      //  cout << x << " " << y << endl;
        for(ll j = 0; j < m; j++){
            if(ara[i][j] == 1){
                x++;
            }
            else{
                y++;
            }
        }
       // getchar();

        ans += (power(2, x) - 1- x);
        ans += (power(2, y) - 1 - y);
    }


    for(int i = 0; i < m; i++){
        ll x = 0, y = 0;
        for(int j = 0; j < n; j++){
            if(ara[j][i] == 1){
                x++;
            }
            else{
                y++;
            }
        }

        ans += (power(2, x) - 1 - x );
        ans += (power(2, y) - 1 - y );

    }

    printf("%I64d\n",ans);
}
