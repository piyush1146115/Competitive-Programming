#include<bits/stdc++.h>
using namespace std;

struct st{
int x, y;
}ara[15];

int dp[(1 << 10) + 5][15];

int n;

int Set(int N, int pos)
{
    return N = N | (1 << pos);
}

int reset(int N, int pos)
{
    return N = N & ~(1 << pos);
}

bool check(int N, int pos)
{
    return (bool)(N & (1 << pos));
}

int dis(st a, st b){
 return (abs(a.x - b.x) + abs(a.y - b.y));
}

st s;

int call(int mask, int prev)
{
    if(mask == ((1 << n)  - 1)){
        return dis(s, ara[prev]);
    }

    if(dp[mask][prev] != -1)
        return dp[mask][prev];

    int ans = 1 << 30;
    for(int i = 0; i < n; i++){

        if(check(mask, i) == 0){
            if(prev == 12)
            ans = min(ans, dis(s, ara[i]) + call(Set(mask, i) , i));
            else
            ans = min(ans, dis(ara[i], ara[prev]) + call(Set(mask, i) , i));
        }
    }
    dp[mask][prev] = ans;
    return ans;
}

int main()
{
    int test;
    scanf("%d", &test);

    int p, q;

    while(test--){
        scanf("%d %d",&p, &q);

        scanf("%d %d",&s.x, &s.y);

        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            scanf("%d %d",&ara[i].x, &ara[i].y);
        }
        memset(dp, -1, sizeof(dp));

        int ans = call(0, 12);

        printf("The shortest path has length %d\n",ans);
    }

}
