#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, i, j, p, q, sum;

    while(scanf("%lld", &n) == 1){
        if(n == 0)
            break;

        p = 1;
        sum = 0;
        while(1){
            sum += p;

            if(sum > n)
                break;
            p++;
        }

 /*       for(i = p; i >= 1; i--){
            if(sum - i == n){
                q = i;
                break;
            }
        }
*/
        printf("%lld %lld\n", sum - n, p);
    }
    return 0;
}
