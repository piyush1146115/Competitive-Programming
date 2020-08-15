#include<stdio.h>
int gcd(int i, int j)
{
    int temp;

    while(j != 0){
        temp = i % j;
        i = j;
        j = temp;
    }
    return i;
}

int main()
{
    int i, j, k, l, n,sum;

    while(scanf("%d",&n) == 1 && n != 0){
            sum = 0;
        for(i = 1; i < n; i++){
            for(j = i+1;j <= n; j++){
                sum += gcd(i, j);
            }
        }
    printf("%d\n",sum);
    }
    return 0;
}
