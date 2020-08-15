#include<bits/stdc++.h>
using namespace std;

long long GCD(long long a, long long b)
{
    if(b == 0)
        return a;
    else return GCD(b, a % b);
}
int main()
{
    long long test, i, k, sum, n, cs = 0;

    scanf("%lld", &test);

    while(test--){
        scanf("%lld", &n);

        sum = (n * (n - 1))/ 2;
        if(sum % 2 == 0){
            printf("Case %lld: %lld\n",++cs,sum / 2);
        }
        else{
            printf("Case %lld: %lld/2\n",++cs, sum);
        }

    }
    return 0;
}
