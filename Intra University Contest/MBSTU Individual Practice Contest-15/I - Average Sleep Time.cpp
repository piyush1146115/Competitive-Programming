#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 200005

ll ara[MAX];

int main()
{
    ll n, m, k;

    scanf("%I64d %I64d", &n, &k);

    for(int i = 1; i <= n; i++){
        scanf("%I64d", &m);
        ara[i] = ara[i - 1] + m;
    }

    double sum = 0.0;
    ll cnt = 0;

    for(int i = k; i <= n; i++){
        sum += (double)(ara[i] - ara[i - k]);
        cnt++;
    }

    double ans = sum/(double)cnt;

    printf("%.10lf\n",ans);
}
