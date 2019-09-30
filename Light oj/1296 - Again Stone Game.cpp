#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[100];
ll fun(ll n)
{
    if(n <= 1)
        return 0;
    if(n % 2 == 0)
        return n/2;

    ll div = 4;
    ll po = 2, base = 1;

    int dif;

    for(int i = 0; (1 << i) <= n; i++)
        dif = n - (1 << i);

    while(1){
        ll temp = dif - base;
        if(temp % div == 0){
            return n/div;
        }
        base += po;
        div *= 2;
        po *= 2;
    }

}

int main()
{

    int n;
    ll ara[1005];
    int test;
memset(dp, -1, sizeof(dp));

    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++){
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
            scanf("%lld", &ara[i]);

        for(int i = 0; i < n; i++){
            if(ara[i] <= 1){
                ara[i] = 0;
            }
            else{
                ara[i] = fun(ara[i]);
            }
//            cout << ara[i] << endl;
        }

        ll ans = 0;

        for(int i = 0; i < n; i++){
            ans = ans ^ ara[i];
        }

        if(ans != 0){
            printf("Case %d: Alice\n",tc);
        }
        else{
            printf("Case %d: Bob\n",tc);
        }
    }
//
//for(int i = 1; i < 65; i++)
//    if(i % 2 == 1)
//    printf("%d %lld\n",i, fun(i));
}
