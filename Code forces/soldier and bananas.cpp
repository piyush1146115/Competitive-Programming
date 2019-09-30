#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k, w, cost, dif;

    cin >> k >> n >> w;
    cost = (w * (w + 1)) / 2;
    cost *= k;

    dif = cost - n;

    if(dif <= 0)
        printf("0\n");
    else
        printf("%lld\n", dif);

    return 0;
}
