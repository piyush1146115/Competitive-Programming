#include<bits/stdc++.h>
using namespace std;
#define mxx 100005
int take[mxx], dp[mxx];
int c[105], am[105];


int main()
{
  int n, m, test;
  scanf("%d", &test);

  for(int tc = 1; tc <= test; tc++){
    scanf("%d %d",&n, &m);

    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < n; i++){
        scanf("%d",&am[i]);
    }

    for(int i = 0; i < n ; i++){
        scanf("%d", &c[i]);
    }
    int ans = 0;
    dp[0] = 1;


    for(int i = 0; i < n; i++){
        memset(take, 0, sizeof(take));

        for(int j = am[i]; j <= m; j++){
            if(dp[j] == 0 && take[j - am[i]] < c[i] && dp[j - am[i]] == 1){
                dp[j] = 1;
                take[j] = take[j - am[i]] + 1;
                ans++;
            }
        }
    }
    printf("Case %d: %d\n",tc, ans);
  }
}
