#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, i, j, sum[1000];

    while(cin >> m >> n){
        i = 0;
        memset(sum, 0, sizeof(sum));
        int k, in = 1;

        while(i < (m *n)){
            scanf("%d",&k);
            sum[in] += k;
            in++;
            if(in == m + 1)
                in = 1;
                i++;
        }
        k = -1;
        for(i = 1; i <= m ; i++)
            k = max(sum[i], k);

        for(i = m; i >= 0; i--){
            if(k == sum[i]){
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
