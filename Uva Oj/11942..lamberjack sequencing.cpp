#include<stdio.h>
int main()
{
    int a, b, c, i, j, n, flag;
    int ara[10];

    scanf("%d",&n);

    for(a = 1; a <= n; a++){
            flag = 0;
        for(b = 0; b < 10; b++){
            scanf("%d",&ara[b]);
        }
        for(i = 0; i < 9; i++){
            if(ara[i] >= ara[i + 1]){
                continue;
            }
            else
                {flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            flag = 0;
            for(i = 0; i < 9; i++){
                if(ara[i] <= ara[i+1]){
                    continue;
                }
                else{
                flag = 1;
                    break;
            }
            }


        }
        if(a == 1){
            printf("Lumberjacks:\n");
        }
        if(flag == 1){
            printf("Unordered\n");
        }
       else if(flag == 0){
            printf("Ordered\n");
        }

    }
    return 0;
}
