#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, ara[150], mx, i, j, k = 0;

    while(scanf("%d %d",&n, &m) == 2){
        memset(ara, 0, sizeof(ara));

        mx = -131131;

        for(i = 1; i <= m; i++){
            for(j = 1; j <= n; j++){
                ara[i + j]++;
                mx = max(mx, ara[i + j]);
                //printf("%d %d %d %d\n",i, j, ara[i +j],i + j);
            }
        }
        if(k)
            printf("\n");

        for(i = 1; i <= m + n; i++)
            if(ara[i] == mx)
                printf("%d\n",i);
        k = 1;
    }
    return 0;
}
