#include<bits/stdc++.h>
using namespace std;
int sum[1000005];
int num[1005];
int main()
{
    //freopen("input.txt", "r", stdin);
    int i, j, q, n, m, s, c = 0;

    while(scanf("%d",&n) == 1 & n != 0){
        for(i = 0; i < n; i++)
            scanf("%d",&num[i]);

            c++;

        s = 0;
        for(i = 0; i < n - 1; i++){
            for(j = i + 1;j < n; j++ ){
                sum[s++] = num[i] + num[j];
            }
        }
        scanf("%d", &m);
        int flag = 1;
        for(i = 0; i < m; i++){
        int ind, dif, mn = 10003434;

        scanf("%d", &q);
        for(j = 0; j < s; j++){
            dif = abs(sum[j] - q);
            if(dif < mn){
                mn = dif;
                ind = j;
            }
        }
        if(flag){
            printf("Case %d:\n", c);
            flag = 0;
        }
        printf("Closest sum to %d is %d.\n",q, sum[ind]);
        }

    }
    return 0;
}
