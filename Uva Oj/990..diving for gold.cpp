#include<bits/stdc++.h>
using namespace std;
#define mxx 35

struct st{
int t, v;
};

st ara[mxx];
int  w, d, n, cnt;
int dp[mxx][1005];
int print[mxx];

int fun(int pos, int weight)
{
    if(pos > n)
        return 0;
        if(dp[pos][weight] != -1)
            return dp[pos][weight];

    int p1 = 0, p2 = 0;

    if(weight + (3 *ara[pos].t*d) <= w)
        p1 = ara[pos].v + fun(pos + 1, weight + (3 *ara[pos].t*d));

    p2 = fun(pos + 1, weight);

    dp[pos][weight] = max(p1, p2);

    return dp[pos][weight];

}

void path(int pos, int weight)
{
    if(pos > n)
        return;

    int x = fun(pos, weight);
    int y = 0;

    if(weight + (3 *ara[pos].t*d) <= w)
        y = fun(pos + 1,weight+ (3 *ara[pos].t*d)) + ara[pos].v;

    if(x == y){
        cnt++;
        print[pos] = 1;
        path(pos + 1, weight+ (3 *ara[pos].t*d));
    }
    else
        path(pos + 1, weight);
}

int main()
{
    int flag = 0;

    while(scanf("%d %d", &w, &d) == 2){

        scanf("%d", &n);

        for(int i = 1; i <= n; i++){
            scanf("%d %d",&ara[i].t, &ara[i].v);
        }
        memset(dp, -1, sizeof(dp));
        int ans = fun(1, 0);
        cnt = 0;
        memset(print, 0, sizeof(print));

        path(1, 0);
        if(flag)
            printf("\n");

        flag = 1;

      printf("%d\n",ans);
      printf("%d\n",cnt);

      for(int i = 1; i <= n; i++)
      if(print[i] == 1){
        printf("%d %d\n",ara[i].t, ara[i].v);
      }

    }
    return 0;
}
