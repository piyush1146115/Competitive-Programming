#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara[105], n, i, j;

    cin >> n;

    for(i = 0; i < n; i++)
        scanf("%d", &ara[i]);

    for(i = 1; i < n; i++){
        if(ara[i - 1] == ara[i]){
         if(i < n - 1){
            if(ara[i + 1] != ara[i]){
                         if(i < n - 2){
                if(ara[i] == ara[i + 2])
                continue;
             }
                swap(ara[i], ara[i + 1]);
            }
         }
         /*else if(i > 1){
            if(ara[i - 2] != ara[i]){
                    if(i > 2){
                        if(ara[ i - 3] == ara[i]){
                            continue;
                        }
                    }
                swap(ara[i - 2], ara[i - 1]);
            }
         }*/
        }
    }

 int flag = 1;
for(i = 1; i < n; i++){
    if(ara[i] == ara[i -1])
    {
        flag = 0;
        break;
    }
}
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
