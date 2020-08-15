#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[1005];
int main()
{
    ll n, l;

    scanf("%lld %lld",&n, &l);

    for(int i = 0; i < n; i++)
        scanf("%lld", &ara[i]);

    sort(ara, ara + n);

    double dif = (double)(ara[0] - 0);
    double ans = dif;

    for(int i = 0; i < n; i++)
    {
        dif = (double)(ara[i + 1] - ara[i]);

        ans = max(ans, dif/2.0);
    }
    dif = (double)(l - ara[n - 1]);
    ans = max(ans, dif);

    printf("%.10lf\n",ans);
}
