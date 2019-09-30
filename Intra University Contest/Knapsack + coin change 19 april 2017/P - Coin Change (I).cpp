#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[52][21][1001];
int c[55], a[55];
int n, k;

ll fun(int pos, int state, int value)
{
    if(value == 0)
        return 1;
    if(value < 0)
        return 0;
    if(pos > n)
        return 0;

    if(dp[pos][state][value] != -1)
        return dp[pos][state][value];

    ll p1 = 0, p2 = 0;

  //  cout << pos << " " << state << " " << value << " " << c[pos] <<  endl;
   // getchar();

    if(state <= c[pos])
    p1 = fun(pos, state + 1, value - a[pos]);

    p2 = fun(pos + 1, 1, value) ;

    dp[pos][state][value] = (p1 + p2) % 100000007;

    return dp[pos][state][value] ;
}

int main()
{
    int test;

    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++){

        scanf("%d %d", &n, &k);

        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        for(int i = 1; i <= n; i++)
            scanf("%d", &c[i]);

        memset(dp, -1, sizeof(dp));

        ll res = fun(1, 1, k);

        printf("Case %d: %lld\n",tc,res);
    }
    return 0;
}
