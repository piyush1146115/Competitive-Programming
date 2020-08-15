#include<stdio.h>
int main()
{
    int ara[100];
    long long int i, j, k, count ,index;

    while(scanf("%lld", &i) == 1 && i != 0){
        index = 0;
        count = 0;
        while(i >= 1){
            j = i % 2;
            i = i /2;
            if(j == 1){
                count++;
            }
            ara[index] = j;
            index++;
        }
        printf("The parity of ");
        for(index--;index >= 0;index--){
            printf("%d",ara[index]);
        }
        printf(" is %lld (mod 2).\n",count);
    }
    return 0;
}
