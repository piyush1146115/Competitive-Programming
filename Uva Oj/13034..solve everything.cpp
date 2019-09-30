#include<stdio.h>
int main()
{
    int ara[13], test, flag, i, a;

    scanf("%d", &test);

    for(i = 1; i <= test; i++){
        flag = 1;
        for(a = 0; a < 13; a++){
            scanf("%d", &ara[a]);
            if(ara[a] <= 0){
                flag = 0;
            }
        }
        if(flag){
            printf("Set #%d: Yes\n", i);
        }
         else
        {
            printf("Set #%d: No\n", i);
        }
    }
    return 0;
}
