#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[13][30005];

int coin[] = { 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

ll make(int pos, int sum)
{
    if(sum < 0)
        return 0;
    if(sum == 0)
        return 1;
    if(pos == 11)
        return 0;

    if(dp[pos][sum] != -1)
        return dp[pos][sum];

    ll p1 = 0, p2 = 0;

    p1 = make(pos, sum - coin[pos]);
    p2 = make(pos + 1, sum);

    return dp[pos][sum] =  p1 + p2;
}

int main()
{
    double d;

    while(scanf("%lf", &d) == 1){
        if(abs(d - 0.00) <= 1e-6)
            break;
        memset(dp, -1, sizeof(dp));
        double t = d;
        d *= 100.0;

        int n = (int)d;

        while(n % 5 != 0){
            n ++;
        }

        ll ans = make(0, n);
        printf("%6.2lf%17lld\n",t, ans);
    }

    return 0;
}
