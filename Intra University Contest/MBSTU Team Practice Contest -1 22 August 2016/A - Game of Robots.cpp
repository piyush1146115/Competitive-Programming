#include<bits/stdc++.h>
using namespace std;
long long int ara[100005];
int main()
{
    long long n, k, i, j, m, s = 0;

    scanf("%lld %lld", &n, &k);

    for(i = 1; i <= n; i++){
        scanf("%lld", &ara[i]);
    }

    for(i = 1;; i++){
        s += i;
        if(s == k){
            printf("%lld\n", ara[i]);
            break;
        }
        if(s > k){
            s -= i;
            m = k - s;
            printf("%lld\n",ara[m]);
            break;
        }
    }
    return 0;
}
