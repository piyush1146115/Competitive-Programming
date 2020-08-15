#include<stdio.h>

int N, Data[101];
int Total;
int dp[101][500001];
void read()
{
    int i;
    Total = 0;

    scanf("%d",&N);

    for(i = 0; i < N; i++){
        scanf("%d", &Data[i]);
        Total += Data[i];
    }
}
void init()
{
    int i, j, m;
    m = (N * 500) + 1;
    for(i = 0; i <= N; i++)for(j = 0; j < m ; j++)
        dp[i][j] = -1;
}

int abs(int i)
{
    if(i < 0)
        return -i;

    return i;
}
int solve(int i, int sum1)
{
    int sum2, left, right;

    if(dp[i][sum1] != -1)
        return dp[i][sum1];

    if(i == N){
        sum2 = Total - sum1;

        return dp[i][sum1] = abs(sum1 - sum2);
    }
    left = solve(i + 1, sum1);
    right = solve(i + 1, sum1 + Data[i]);

    if(left < right)
        return dp[i][sum1] = left;
    else
        return dp[i][sum1] = right;
}

int main()
{
    int T;

    scanf("%d",&T);

    while(T--){
        read();
        init();
        printf("%d\n", solve(0, 0));
    }
    return 0;
}
