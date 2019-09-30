#include<stdio.h>
int main()
{
    int test, a, i, n, flag, count, res;
    char c;
    scanf("%d", &test);

    for(i = 1; i <= test; i++){
        count = 0;
        flag = 0;
        scanf("%d", &n);

        for(a = 1; a <= n; a++){
            getchar();
            scanf("%c",&c);
               if(c == 'W'){
                count = -1;
             }
            count++;

            if(count == 3 && flag == 0){
                res = a;
                flag = 1;
            }

        }
        if(flag == 1){
            printf("Case %d: %d\n", i, res);
        }
        else{
            printf("Case %d: Yay! Mighty Rafa persists!\n",i);
        }

    }
    return 0;
}
