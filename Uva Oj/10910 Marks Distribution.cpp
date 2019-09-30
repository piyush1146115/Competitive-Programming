#include<bits/stdc++.h>
using namespace std;

int n, t, p;
int dp[75][75];


int fun(int pos, int sum) {
    if (sum  > t)
        return 0;

    if (pos == n) {
        if (sum == t)
            return 1;
        else
            return 0;
    }
    if(dp[pos][sum] != -1)
    return dp[pos][sum];

    int p1 = 0;

    for (int i = 0; i <= t; i++) {
        p1 += fun(pos + 1, sum + i);
    }
    
    return dp[pos][sum] = p1;
}

int main() {
    int test;

    scanf("%d", &test);

    while (test--) {
		memset(dp, -1, sizeof(dp));
        scanf("%d %d %d", &n, &t, &p);

        t = t - (n * p);

        int ans = fun(0, 0);

        printf("%d\n", ans);
    }
    return 0;
}
