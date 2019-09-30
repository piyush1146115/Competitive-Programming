#include<bits/stdc++.h>
using namespace std;

int dp[105][10205];
int price[105], favor[105];
int n, m;

int fun(int pos, int sum)
{
    if(sum > m + 200)
        return -999999;


    if(pos == n){
        //cout << sum << endl;
   // getchar();
     if(sum <= m + 200 && sum > 2000)
        return 0;
     if(sum <= m)
     return 0;

        return -999999;
    }

        if(dp[pos][sum] != -1)
            return dp[pos][sum];

    int p1 = 0,p2 = 0;


    p1 = favor[pos] + fun(pos + 1, sum + price[pos]);

    p2 = fun(pos + 1, sum );

    return dp[pos][sum] = max(p1, p2);
}

int main()
{

  while(scanf("%d %d", &m, &n) == 2){

        memset(dp, -1, sizeof(dp));

    for(int i = 0; i < n; i++){
        scanf("%d %d",&price[i], &favor[i]);
    }


    int ans = fun(0, 0);

    printf("%d\n",ans);
  }
}
