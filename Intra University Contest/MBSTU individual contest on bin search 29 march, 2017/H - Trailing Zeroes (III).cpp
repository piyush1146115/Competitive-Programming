#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll calc(ll n)
{
    ll div = 5, cnt = 0;

    while(1)
    {
        cnt += n/div;
        if(n/div <= 0)
            break;
        div *= 5;
    }
    return cnt;
}

ll bin(ll n, ll key)
{
    ll lo = 1, hi = n, mid, ans = -1;

    while(lo <= hi)
    {
        mid = (lo + hi)/2;
        ll res = calc(mid);

        if(res == key)
        {
            ans = mid;
            hi = mid -1;
        }
        else if(res < key)
        {
            lo = mid + 1;
        }
        else if(res > key)
        {
            hi = mid - 1;
        }
    }
    return ans;

}

int main()
{
    int test;

    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++)
    {
        ll n;
        scanf("%lld", &n);
        ll ans = bin(n*10, n);

        printf("Case %d: ",tc);

        if(ans == -1)
            printf("impossible\n");
        else
            printf("%lld\n",ans);
    }
return 0;
}
