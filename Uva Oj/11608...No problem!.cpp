#include<stdio.h>
int main()
{
    int n, a, i, j ,caseno = 0;
    int sum[15], flag[15];

    while(scanf("%d",&n)== 1 && n >= 0){
        sum[0] = n;

        for(i = 1; i <= 12; i++){
            scanf("%d", &a);
            sum[i] = sum[i - 1] + a;
            flag[i] = 0;
        }

        for(i = 1; i <= 12; i++){
            scanf("%d", &a);
            if(a <= sum[i -1]){
                flag[i] = 1;
                for(j = i; j <= 12; j++){
                    sum[j] -= a;
                }
            }
        }
        printf("Case %d:\n",++caseno);

        for(i = 1; i <= 12; i++){
            if(flag[i] == 1){
                printf("No problem! :D\n");
            }
            else{
                 printf("No problem. :(\n");
            }
        }
    }
    return 0;
}
