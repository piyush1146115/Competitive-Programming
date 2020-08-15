#include<stdio.h>
int main()
{
    long long int  sum, dif, n, a,l,m;

    scanf("%lld",&n);

    for(a = 1; a <= n;a++){
        scanf("%lld %lld",&sum,&dif);
        l = (sum - dif)/2;
        m = (sum + dif)/2;
        if((m + l) != sum || dif > sum){
            printf("impossible\n");
        }
        else{

            printf("%lld %lld\n",m,l);
        }
    }
    return 0;
}
