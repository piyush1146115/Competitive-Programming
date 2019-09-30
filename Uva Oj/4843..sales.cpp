#include<stdio.h>
int main()
{
    int ara[5005];
    int n, i, j, k, count, test;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);

        for(i = 0; i < n; i++){
            scanf("%d", &ara[i]);
        }

        count = 0;

        for(i = 1; i < n;i++){
            for(j = 0; j < i;j++){
                if(ara[i] >= ara[j]){
                    count++;
                }
            }
        }

        printf("%d\n",count);
    }
    return 0;
}
