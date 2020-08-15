#include<stdio.h>
int main()
{
    int a, b, t, ara[5],count;


    while(scanf("%d",&t) == 1){
            count = 0;
        for( a = 0; a < 5; a++){
            scanf("%d",&ara[a]);
            if(ara[a] == t){
                count++;
            }
        }
        printf("%d\n",count);
    }
return 0;
}
