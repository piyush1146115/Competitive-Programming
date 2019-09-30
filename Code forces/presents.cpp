#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara[150], n, i, j;

    cin >> n;

    for(i = 1; i <= n; i++)
        scanf("%d",&ara[i]);

    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
        if(ara[j] == i){
            printf("%d ",j);
            break;
        }
        }
    }
    printf("\n");

    return 0;
}
