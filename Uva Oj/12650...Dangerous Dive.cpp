#include<stdio.h>
int main()
{
    int ara[10005];
    int a, i, n, r;

    while(scanf("%d %d",&n, &r) == 2){
        for(i = 1; i <= n; i++){
            ara[i] = 0;
        }
        for(i = 1; i <= r; i++){
            scanf("%d", &a);
            ara[a] = 1;
        }
        if(n == r){
            printf("*\n");
        }
        else{
            for(i = 1; i <= n; i++){
                if(ara[i] == 0){
                    printf("%d ",i);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
