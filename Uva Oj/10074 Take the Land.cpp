#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mat[105][105], sum[105][105];

int main()
{
    ll a, b, m, n;

    while(scanf("%lld %lld",&m, &n) == 2){

        if(m == 0 && n == 0)
            break;

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                scanf("%lld", &mat[i][j]);
            }
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                //scanf("%lld", &mat[i][j]);
                if(mat[i][j] == 0){
                    mat[i][j] = 1;
                }
                else{
                    mat[i][j] = -999999999999;
                }
            }
        }

        memset(sum, 0, sizeof(sum));

     for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            sum[j][i] = sum[j - 1][i] + mat[j][i];
        }
    }
            ll mxx = 0;



    for(int i = 1; i <= m; i++){
        for(int j = i; j <= m; j++){
            ll s = 0;
        for(int x = 1 ; x <= n; x++){
            s += (sum[j][x] - sum[i - 1][x]);
            if( s < 0)
                s = 0;

            if(mxx < s)
                mxx = s;
        }
    }
 }
    cout << mxx << endl;

    }
}
