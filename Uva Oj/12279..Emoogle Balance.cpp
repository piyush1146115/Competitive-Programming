#include<stdio.h>
int main()
{
    int a, b, c, d = 0, count,count2, n;

    while(scanf("%d",&n) == 1 && n != 0){
            d++;
            count = 0;
            count2 = 0;
        for(a = 1; a <= n; a++){
            scanf("%d",&b);
            if(b == 0){
                count++;
            }
            else{
                count2++;
            }
        }
        c = count2 - count;
        printf("Case %d: %d\n",d,c);
    }
    return 0;
}
