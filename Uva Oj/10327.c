#include<stdio.h>
int main()
{
    int n, a, b, count,d,temp;
    int ara[1005];

    while(scanf("%d",&n) == 1){
        for(a = 0; a < n; a++){
            scanf("%d",&ara[a]);
        }
    count = 0;
        for(a = 0; a < n-1; a++){
            for(b = 0; b < n - 1; b++){
                if(ara[b+1] < ara[b]){
                    temp = ara[b];
                    ara[b] = ara[b+1];
                    ara[b+1] = temp;
                    count++;
                }
            }
        }

            printf("Minimum exchange operations : %d\n",count);
    }
    return 0;
}
