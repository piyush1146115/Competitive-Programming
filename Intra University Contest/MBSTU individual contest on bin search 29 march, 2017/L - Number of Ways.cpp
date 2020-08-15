#include<bits/stdc++.h>
using namespace std;
#define mxx 500005
#define ll long long

ll ara[mxx + 5];

int main()
{
    ll n, sum = 0;
    scanf("%lld", &n);
        sum = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%lld",&ara[i]);
        sum += ara[i];
    }

    if(sum % 3 != 0)
    {
        printf("0\n");
    }
    else
    {
        ll d = sum / 3;

        for(int i = 1; i < n; i++)
            ara[i] += ara[i - 1];

        ll cnt = 0, ans = 0;

        for(int i = 0; i < n - 1; i++)
        {

             if(ara[i] == d * 2)
                ans += cnt;
               if(ara[i] == d)
                cnt++;
        }

        printf("%lld\n",ans);
    }

    return 0;
}
