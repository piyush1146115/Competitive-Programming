#include<bits/stdc++.h>
using namespace std;
#define mxx 105
#define inf 1e5
int mat[mxx][mxx], sum[mxx][mxx];

int main()
{
    int test;

    scanf("%d", &test);

    while(test--){

       int b, s, row, col;

       scanf("%d", &s);
       row = col = s;

       for(int i = 0; i <= s; i++){
        for(int j = 0; j <= s; j++){
            mat[i][j] = 1;
        }
       }

        scanf("%d", &b);

        while(b--){
            int r1, c1, r2, c2;

            scanf("%d %d %d %d",&r1, &c1, &r2, &c2);

            for(int i = r1; i <= r2;i++){
                for(int j = c1; j <= c2; j++){
                    mat[i][j] = -999999;
                }
            }
        }

        memset(sum , 0 , sizeof(sum));

        for(int i = 1; i <= col; i++){
            for(int j = 1; j <= row; j++){
                sum[j][i] = sum[j - 1][i] + mat[j][i];
            }
        }

        int mx = 0;

        for(int i = 1; i <= row; i++){
            for(int j = i; j <= row; j++){
                int ss = 0;

                for(int x = 1; x <= col ;x++){
                    ss += sum[j][x] - sum[i - 1][x];

                    if(ss < 0)
                        ss = 0;
                    mx = max(ss, mx);
                }
            }
        }

        printf("%d\n",mx);
    }
}
