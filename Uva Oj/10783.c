#include<stdio.h>
int main()
{
    int test, i, j, a, b, count = 0, sum;

    scanf("%d", &test);

    for(i = 1; i <= test; i++){
        count++;
        sum = 0;
        scanf("%d %d", &a, &b);

        for(j = a; j <= b; j++){
            if(j % 2 != 0)
                sum += j;
        }

        printf("Case %d: %d\n",count, sum);
    }
return 0;
}
