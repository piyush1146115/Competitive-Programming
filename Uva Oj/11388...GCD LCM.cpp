#include<stdio.h>
int main()
{
    unsigned long long int a, b, c, d,x, gcd, lcm;
    int test,i;
    scanf("%d",&test);

    for(i = 1; i <= test; i++){
    scanf("%llu %llu",&gcd,&lcm);

    x = gcd * lcm;
    if(lcm % gcd != 0){
        printf("-1\n");
    }
    else{
    for(a = gcd; a <= lcm; a+= a){
        c = x/a;
        d = c * a;
        if(d == x){
            break;
        }
    }
    printf("%llu %llu\n",a, c);
    }
    }
    return 0;
}
