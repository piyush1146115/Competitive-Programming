#include<bits/stdc++.h>
using namespace std;
 long long ara[10000005];
int main()
{
    //solve();
   long long  int n, b, i, j, a, test = 0;
   /// int test = 0;

    while(scanf("%lld %lld", &n, &b) == 2){
            if(n == 0 && b == 0)
            break;
        ara[0] = 1;
    ara[1] = 1;

    for(a = 2; a <= 1000005; a++){
        ara[a] = (ara[a - 1] + ara[a - 2] + 1) % b;
        if(ara[a] == 1 && ara[a - 1] == 1)
            break;
    }
    a--;

        printf("Case %lld: %lld %lld %lld\n",++test, n, b, ara[n % a]);
    }
    return 0;
}
