#include<stdio.h>
#include<math.h>
int main()
{
    int ara[3500], flag[3500];
    int a, b, n;

    while(scanf("%d",&n) == 1){
        for(a = 0; a < n; a++){
            scanf("%d", &ara[a]);
            flag[a] = 0;
        }
        for(a = 0; a < n - 1 ; a++){
            b = fabs(ara[a + 1] - ara[a]);
           /* if(b < 0){
                b = -1 * b;
            }*/
            flag[b] = 1;
        }
        for(a = 1; a < n;a++){
            if(flag[a] != 1){
                break;
            }
        }
        if(a == n){
            printf("Jolly\n");
        }
        else{
            printf("Not jolly\n");
        }


    }
    return 0;
}
