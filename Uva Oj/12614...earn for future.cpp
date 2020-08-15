#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long test, mx,  cse = 0, n, i, j, in;

    cin >> test;

    for(i = 1; i <= test; i++){
        scanf("%lld",&n);
        mx = -134213;
        for(j = 1; j <= n; j++){
            scanf("%lld",&in);
            mx = max(mx, in);
        }
        printf("Case %lld: %lld\n", i, mx);
    }
    return 0;
}
