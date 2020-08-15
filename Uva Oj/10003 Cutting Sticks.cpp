#include<bits/stdc++.h>
using namespace std;
int n;
int ara[55];
int dp[1005][1005];

int fun(int left, int right)
{

    int flag = 0;
    int ans = 1 << 30;

    if(dp[left][right] != -1)
        return dp[left][right];

    for(int i = 0; i < n; i++){
        if(ara[i] >= left && ara[i] < right){
            flag = 1;
            ans = min(ans, ((right - left + 1) + fun(left, ara[i]) + fun(ara[i] + 1, right)));
        }
    }
    if(flag == 0)
        ans = 0;

//    cout << left << " " << right << " " << ans << endl;
//    getchar();

    return dp[left][right] = ans;
}

int main()
{
    int len;

    while(scanf("%d", &len) == 1)
    {
        if(len == 0)
            break;

        memset(dp, -1, sizeof(dp));

        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            scanf("%d", &ara[i]);
        }

        int ans = fun(1, len);

        printf("The minimum cutting is %d.\n",ans);
    }
    return 0;
}
