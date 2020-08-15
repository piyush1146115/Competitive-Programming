#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara[1450], n, i, flag;

    while(scanf("%d",&n) == 1 && n != 0){

        for(i = 0; i < n; i++)
            scanf("%d",&ara[i]);

        sort(ara, ara + n);
        flag = 1;
        for(i = 1; i < n ; i++){
            if(ara[i] - ara[i - 1] > 200){
            flag = 0;
            break;
            }
        }
        if(2 *(1422 - ara[n - 1]) > 200)
            flag = 0;

        if(flag)
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;

}
