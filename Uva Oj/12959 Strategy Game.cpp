#include<bits/stdc++.h>
using namespace std;
int sum[505];
int main()
{
    int n, r, i, j, mx, in, ans;

    while(scanf("%d %d",&n, &r) == 2){
        memset(sum, 0, sizeof(sum));
        mx = - 1;

        for(j = 1; j <= r; j++){
            for(i = 1; i <= n; i++){
                scanf("%d",&in);
                sum[i] += in;
                if(sum[i] > mx)
                    mx = sum[i];
            }
        }

        for(i = n; i >= 1; i--){
            if(sum[i] == mx){
                ans = i;
                break;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
