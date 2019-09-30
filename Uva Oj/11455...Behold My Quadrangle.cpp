#include<stdio.h>
int main()
{
    long long int a, b, c, d, e;
    int test;

    scanf("%d",&test);

    while(test--){
        scanf("%lld %lld %lld %lld",&a, &b, &c, &d);

        if(a == b && a == c && a == d){
            printf("square\n");
        }
        else if((a == b && c == d) || (a == c && b == d) || (a == d && b == c)){
            printf("rectangle\n");
        }
        else if((a + b + c > d) && (a + c + d > b) && (a + b + d > c) && (b + c + d > a)){
            printf("quadrangle\n");
        }
        else{
            printf("banana\n");
        }
    }
    return 0;
}
