#include<stdio.h>
int main()
{
    int a, b,c = 0, d, n, sum;

    while(scanf("%d",&n) == 1 && n >= 0){
        sum = 1;
        d = 0;
        for(b = 1; ; b++){
            if(sum >= n && sum){
                break;
            }
            sum = sum * 2;
            d++;
        }
        c++;
        printf("Case %d: %d\n",c,d);
    }
return 0;
}
