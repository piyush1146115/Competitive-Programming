#include<stdio.h>
int main()
{
    long long int n, a, b, c, d, e, f, g, j, k;
    int ara[10];
    scanf("%lld",&n);
    for(a = 1; a < 10; a++){
        b = n * a;
        g = 0;
        d = b;
        for(f = 0; f < 10; f++){
            ara[f] = 0;
        }
        while(d >= 1){
            e = d % 10;
            d = d /10;
            ara[e]++;
            if(ara[e] > 1){
                    g = 1;
                break;
            }
        }
        if(g != 1)
        printf("%lld / %lld = %lld\n",b, a, n);
    }
    return 0;
}
