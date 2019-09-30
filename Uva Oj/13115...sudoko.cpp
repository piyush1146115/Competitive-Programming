#include<bits/stdc++.h>
using namespace std;
int main()
{
   // freopen("input.txt", "r", stdin);
    int ara[30], grid[27][27], i, j, n, test;

    cin >> test;

    while(test--){
        scanf("%d", &n);
        int r = 1, c = 1, g = 1, k;

        for(i = 0 ; i < n; i++){
           // memset(ara, 0, sizeof(ara));
            for(j = 0; j < n; j++){
              scanf("%d", &grid[i][j]);
            }
        }

        for(i = 0 ; i < n && r == 1; i++){
            memset(ara, 0, sizeof(ara));
            for(j = 0; j < n; j++){
              ara[grid[i][j]]++;
            }
            for( k = 1; k <= n; k++){
                if(ara[k] > 1)
                {
                    r = 0;
                    break;
                }
            }
        }
        for(i = 0 ; i < n && c == 1; i++){
            memset(ara, 0, sizeof(ara));
            for(j = 0; j < n; j++){
              ara[grid[j][i]]++;
            }
            for( k = 1; k <= n; k++){
                if(ara[k] > 1)
                {
                    c = 0;
                    break;
                }
            }
        }
        int ist, jst, sq;
         sq = sqrt(n);

         jst = ist = 0;

         while(ist < n && g == 1){
            jst = 0;
            while(jst < n && g == 1){
                    memset(ara, 0, sizeof(ara));
                for(i = ist; i < ist + sq; i++){
                    for(j = jst; j < jst + sq; j++){
                        ara[grid[i][j]]++;
                    }
                }
                jst += sq;
                for(k = 1; k <= n; k++ ){
                    if(ara[k] > 1)
                    {
                        g = 0;
                        break;
                    }
                }
            }
            ist += sq;
         }

         if(r == 1 && c == 1 && g == 1)
            printf("yes\n");
         else
            printf("no\n");
    }
    return 0;
}
