#include <stdio.h>
int num[1000006];
int main()
{
    unsigned long long n;
    int test, sum;

    scanf("%d", &test);

    while(test--){
        scanf("%llu", &n);
        sum = 0;
        while(n >= 1){
            if(n % 2 == 1)
                sum++;

            n /= 2;
        }
        printf("%d\n", sum);
    }
    return 0;
}

