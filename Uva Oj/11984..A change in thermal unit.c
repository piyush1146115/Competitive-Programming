#include<stdio.h>
int main()
{
    int c, f;
    float  result, i, j, k;
    int a, b, test;

    scanf("%d", &test);

    for(a = 1; a <= test; a++){
        scanf("%d %d",&c, &f);
        i = (1.8 * c) + 32;
        j = f + i;
        result = (j - 32) * .5555555556;

        printf("Case %d: %0.2f\n",a, result);
    }
    return 0;
}
