#include<stdio.h>
int main()
{
    int test, ara[10005][3];
    int a, b, c, f;
    long long sum;

    scanf("%d", &test);

    for(a = 0; a < test; a++){
        scanf("%d", &f);
        sum = 0;
        for(b = 0; b < f; b++){
            for(c = 0; c < 3;c++){
                scanf("%d", &ara[b][c]);
            }
            sum = sum + (ara[b][0] * ara[b][2]);
        }
        printf("%lld\n",sum);
    }
return 0;
}
