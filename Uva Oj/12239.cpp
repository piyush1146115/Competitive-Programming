#include<bits/stdc++.h>
using namespace std;
int main()
{
    int b[150], n , B,  check[150], i, j, k;

    while(scanf("%d %d",&n, &B) == 2){

        if(B == 0 &&  n == 0)
            break;

        for(i = 0; i < B; i++){
            scanf("%d",&b[i]);
        }
        memset(check, 0, sizeof(check));

        for(i = 0; i < B; i++){
            for(j = 0; j < B; j++){
                k = abs(b[i] - b[j]);
                check[k]++;
            }
        }

        for(i = 0; i <= n; i++){
            if(check[i] == 0)
                break;
        }

        if(i == n + 1)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
