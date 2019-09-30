#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[10000 + 5];
int n, m;
vector<ll> vec, fin;
bool chk(int v)
{
    int cnt = 1, sum = 0;

    for(int i = 0; i <= n; i++)
    {
        if(sum + ara[i] > v)
        {
            cnt++;
            //vec.push_back(sum);
            sum = 0;
        }
        if(ara[i] > v)
            return false;
        if(cnt > m)
            return false;
        sum += ara[i];
    }
    return true;
}
/*
3 2
30 30 5 2
*/
int main()
{
    int test;
    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++)
    {
        scanf("%d %d", &n, &m);
        m++;
        ll lo = 1, hi = 0, mid;
        for(int i = 0 ; i <= n; i++)
        {
            scanf("%lld",&ara[i]);
            hi += ara[i];
        }
        ll ans;
        while(lo <= hi)
        {
            mid = (lo + hi)/2;
            if(chk(mid) == true)
            {
                hi = mid - 1;
                ans = mid;
               // vec.clear();
            }
            else
            {
                lo = mid + 1;
            }
        }

        printf("Case %d: %lld\n",tc, ans);
        ll sum = 0, cnt = 1, flag = 0;

        for(int i = 0; i <= n; i++)
        {
            if(sum + ara[i] > ans){
                cnt++;
                printf("%lld\n", sum);
                sum = ara[i];
            }
            else if((m - cnt) == n - i){
                cnt++;
                sum += ara[i];
                printf("%lld\n", sum);
                sum = 0;
            }
            else
                sum += ara[i];
        }

        //printf("%lld\n",sum);
    }
    return 0;
}

