#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long long int n, r, m, k, i, j, sum;
     double x;
    while(scanf("%lld %lld",&m, &k) == 2){
        r = max(m - k, k);
        x = 0;

        for(i = m; i > r;i--){
            x += log10(i);
        }

        if(r == k){
            for(i = 1; i <= m - k; i++){
                x -= log10(i);
            }
        }
        else{
            for(i = 1; i <= k; i++){
                x -= log10(i);
            }
        }
        sum = ( (long long)x + 1 );

        printf("%lld\n", sum);
    }
    return 0;
}
