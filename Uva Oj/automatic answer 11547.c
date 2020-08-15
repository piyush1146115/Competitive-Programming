#include<stdio.h>
int main()
{
    long long int n,a, b, i, j ,k;
    int test;
    scanf("%d", &test);

    for(j = 1; j <= test; j++){
    scanf("%lld",&n);

    a = n * 63 + 7492;
    b = a * 5 - 498;
    k = 2;

    while(k != 0){
        i = b % 10;
        b = b / 10;
        k--;
    }
    if(i < 0){
        i = i * -1;
    }

    printf("%lld\n",i);
    }
    return 0;
}
