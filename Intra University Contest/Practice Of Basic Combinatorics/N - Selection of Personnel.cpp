#include<bits/stdc++.h>
using namespace std;

long long dp[800][10];

long long nCr(long long n, long long r)
{
    if(r == 1){
        return n;
    }
    if(n == r){
        return 1;
    }

    if(dp[n][r] != -1){
        return dp[n][r];
    }
    else{
        dp[n][r] = nCr(n - 1, r) + nCr(n - 1, r - 1);
        return dp[n][r];
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));

    long long n, ans;
    cin >> n;

    ans = nCr(n, 5) + nCr(n, 6) + nCr(n, 7);

    cout << ans << endl;
}
