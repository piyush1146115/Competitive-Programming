#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long test, n, T, p, res, temp;

    scanf("%lld",&test);

    while(test--){
        scanf("%lld %lld %lld",&n, &T, &p);

        temp = T % p;

        res = (temp * n) + n;

        printf("%lld\n",res);
    }
    return 0;
}
