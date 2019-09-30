#include<stdio.h>
int main()
{
    unsigned long long a, b;
    int m, n, l ,count;

    while(scanf("%llu %llu", &a, &b) == 2 && (a != 0 || b != 0)){
    l = 0;
    count = 0;

    while(a >= 1 || b >= 1){
        m = a % 10;
        n = b % 10;

        a = a/10;
        b = b/10;
        if(l >= 10){
            m++;
        }
        l = m + n;
        if(l >= 10){
            count++;
        }
    }
    if(count == 0){
        printf("No carry operation.\n");
    }
    else if(count == 1){
        printf("1 carry operation.\n");
    }
    else{
        printf("%d carry operations.\n",count);
    }
 }
return 0;
}
