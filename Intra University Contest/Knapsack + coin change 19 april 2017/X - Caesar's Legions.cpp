#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 100000000

ll dp[105][105][3][12];

ll n1, n2, k1, k2;

ll fun(ll f, ll h, ll state, ll total)
{
  //  cout << f << " " << h << " " << state << " " << total << endl;
  //  getchar();
    if(f == n1 && h == n2)
        return 1;
    if(f == n1 && total >= k2 && state == 1 && h < n2)
        return 0;
    if(h == n2 && total >= k1 && state == 0 && f < n1)
    return 0;

    if(dp[f][h][state][total] != -1)
    return dp[f][h][state][total];


    ll p1 = 0, p2 = 0;
    if(state == 0){
            if(f < n1 && total < k1)
            p1 = fun(f + 1, h, state, total + 1);
            if(h < n2)
            p2 = fun(f, h + 1, 1, 1);
    }
    if(state == 1)
    {
        if(h < n2 && total < k2)
            p1 = fun(f, h+1, state, total + 1 );
        if(f < n1)
        p2 = fun(f+ 1, h, 0, 1);
    }

    dp[f][h][state][total] = (p1 + p2) % mod;

    return dp[f][h][state][total];
}

int main()
{

    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp, -1, sizeof(dp));
    //cout << n1  << " " << n2 << endl;

    ll res = 0;

    res = max( res, fun(0,0, 0, 0));
   //res = max( res, fun(0,0, 1, 0));

    cout << res << endl;

}
