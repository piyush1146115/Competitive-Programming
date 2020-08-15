#include<bits/stdc++.h>
using namespace std;
int a[1010];
int m, tot;
int dp[101][50001];
int dif;
void coin(int pos, int sum)
{
    int val = tot - sum;
    dif = min(dif, abs(sum-val));
    if(pos == m) return;
    if(dp[pos][sum]!=-1)
    {
        dif = min(dif,dp[pos][sum]);
        return;
    }
    coin(pos+1, sum+a[pos]);
    coin(pos+1, sum);
    dp[pos][sum] = dif;
}

int main()
{
//    freopen("out.txt","w",stdout);
    int TC;
    cin >> TC;
    while(TC--){
    scanf("%d",&m);
    dif = INT_MAX/3;
    memset(dp, -1, sizeof(dp));
    tot = 0;
    for(int i=0; i<m; i++)
    {
        scanf("%d",&a[i]);
        tot += a[i];
    }
    coin(0,0);
    cout << dif << endl;
    }
}
