#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara[100], i, j, k, n;

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &ara[i]);
    }

    if(n == 1)
    {

        if(ara[0] == 15)
            printf("DOWN\n");
        else if(ara[0] == 0)
            printf("UP\n");
        else{
            printf("-1\n");
        }
    }
    else{
        if(ara[n - 1] - ara[n - 2] == 1){
            if(ara[n - 1] != 15){
                printf("UP\n");
            }
            else{
                printf("DOWN");
            }
        }
        else{
            if(ara[n - 1] != 0){
                printf("DOWN\n");
            }
            else{
                printf("UP\n");
            }
        }
    }
    return 0;
}
