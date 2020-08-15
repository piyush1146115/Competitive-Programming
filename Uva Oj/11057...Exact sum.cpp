#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    long long ara[10005];
    long long a, b, n, k, price, min, pos, x, y, dif;
    int flag;
    while(scanf("%lld",&n) == 1){
        flag = 1;
        min = 1000000000;
        for(a = 0; a < n; a++)
            scanf("%lld", &ara[a]);

        scanf("%lld", &price);

        sort(ara, ara + n);

        for(a = 0; a < n -1; a++){
                if( ara[a] < price){
            for(b = a + 1;b < n; b++){

                if(ara[a] + ara[b] == price){
                    dif = ara[b] - ara[a];
                    //printf("dif = %lld\n",dif);
                    if(dif < min){
                        min = dif;
                        x = ara[a];
                        y = ara[b];
                    }
                    break;
                }
            }

            }
        }


    printf("Peter should buy books whose prices are %lld and %lld.\n\n",x, y);
    }
    return 0;
}
