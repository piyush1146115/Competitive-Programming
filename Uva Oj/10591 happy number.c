#include<stdio.h>
int main()
{
    unsigned long long int n, sum, i, j;
    int count,test, a;

    scanf("%d", &test);

    for(a = 1; a <= test; a++){
        scanf("%llu", &n);
        j = n;
        loop:
        sum = 0;
        while(j >= 1){
            i = j % 10;
            sum = sum + i*i;
            j = j/10;
        }
        if(sum >= 10){
            j = sum;
            goto loop;
        }

        else if(sum == 1)
            printf("Case #%d: %llu is a Happy number.\n",a,n);

            else{
                printf("Case #%d: %llu is an Unhappy number.\n",a,n);
            }
    }

    return 0;
}
