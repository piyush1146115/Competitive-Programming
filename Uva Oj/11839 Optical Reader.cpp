#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, n, ara[10], flag, ans;
    //freopen("input.txt", "r", stdin);

    while(scanf("%d", &n) == 1 && n != 0){
        while(n--){
            flag = 0;
            for(i = 0; i < 5; i++){
                scanf("%d",&ara[i]);
            }
            for(i = 0; i < 5; i++){
                if(ara[i] <= 127){
                    if(flag == 1){
                        flag = 0;
                        break;
                    }
                    flag = 1;
                    ans = i;
                }
            }
            if(flag){
                printf("%c\n",ans + 65);
            }
            else{
                printf("*\n");
            }
        }
    }
    return 0;
}
