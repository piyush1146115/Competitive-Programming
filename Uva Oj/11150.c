#include<stdio.h>
int main()
{
    int n, a, b, c, i, j, k,sum = 0;

    while(scanf("%d",&n) == 1 && n != 0){
        a = n / 3;
        b = n % 3;
        i = a + b;
        sum =  a;
        while(i >= 3){
            a = i / 3;
            sum =sum + a;
            b = i % 3;
            i = a + b;
        }
        if(i == 2){
            sum = sum + 1;
        }
        printf("%d\n",sum);
    }
return 0;
}
