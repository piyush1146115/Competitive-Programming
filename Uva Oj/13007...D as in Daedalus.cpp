#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    long long n, m, xsum, osum, bud[52], sum[52], play[52][22], i, j, k;
    long long c[5] = {1, 10, 100, 1000, 10000};

    while(scanf("%lld %lld",&n, &m) == 2){
        xsum = 0;
        osum = 0;
        for(i = 0; i < m; i++){
                sum[i] = 0;
                scanf("%lld", &bud[i]);
            for(j = 0; j < n; j++){
                scanf("%lld", &play[i][j]);
                sum[i] += play[i][j];
            }
            if(sum[i] <= bud[i] )
                xsum += play[i][0];
        }

        for(i = 0; i < m; i++){
            sum[i] -= play[i][0];
            if(sum[i] < bud[i]){
                for(j = 4; j >= 0; j--){
                    if(sum[i] + c[j] <= bud[i]){
                        osum += c[j];
                        break;
                    }
                }
            }
        }

        printf("%lld\n",  osum - xsum);

    }
    return 0;
}
