#include<stdio.h>
//long int ara[1005];
int main()
{
    long int a, b, c, i, j, k, sum, test,res, sum2;

        scanf("%ld", &test);

    c = 0;
    while(test--)
    {
        c++;

        scanf("%ld %ld %ld",&i, &j, &k);
        sum = 0;
    for(a = 1; a <= i;a++){
        sum = sum + a;
    }

        sum2 = 0;
        for(b = k; b < j + k; b++){
            sum2 += b;
        }
        res = sum - sum2;

        printf("Case %ld: %ld\n",c, res);
    }
    return 0;
}
