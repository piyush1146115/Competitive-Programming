#include<stdio.h>
int main()
{
    long long int a, lim,i;
    int count, d = 0;


    while(scanf("%lld %lld",&a,&lim) == 2){
            d++;
    i = a;
    if(a == -1 && lim == - 1){
        break;
    }
    count = 1;
    while(a != 1){
            count++;
        if(a % 2 == 0){
            a = a/2;
        }
        else{
            a = 3*a + 1;
        }
        if(a > lim){
                count--;
            break;
        }
    }
    printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",d, i, lim, count);
    }
    return 0;
}
