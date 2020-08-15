#include<bits/stdc++.h>
using namespace std;
#define ll long long
int ara[10000 + 5];
int n, m;

bool chk(int v)
{
    int cnt = 1, sum = 0;

    for(int i = 0; i < n; i++){
        if(sum + ara[i] > v){
            cnt++;
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

int main()
{
    int test;
    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++){
        scanf("%d %d", &n, &m);

        ll lo = 1, hi = 0, mid;
        for(int i = 0 ; i < n; i++){
            scanf("%d",&ara[i]);
            hi += ara[i];
        }
        ll ans;
        while(lo <= hi){
            mid = (lo + hi)/2;
            if(chk(mid) == true){
                hi = mid - 1;
                ans = mid;
            }
            else{
                lo = mid + 1;
            }
        }
        printf("Case %d: %lld\n",tc, ans);
    }
    return 0;
}
