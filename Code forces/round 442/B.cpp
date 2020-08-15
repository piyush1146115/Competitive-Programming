#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

string s;

ll dp[5005][5];

ll fun(int pos, int state)
{
    if(state > 2)
        return -1;

    if(pos >= (int)s.size())
        return 0;

    if(dp[pos][state] != -1)
        return dp[pos][state];

    ll ret = 0;


    if(state  == 1)
    {
        if(s[pos] == 'b')
        {
            ret = 1 + fun(pos + 1, state);
        }
        else
        {
            ll ret1 = 1 + fun(pos + 1, state + 1);
            ll ret2 = fun(pos + 1, state);
            ret = max(ret1, ret2);
        }

    }
    else
    {

        if(s[pos] == 'a')
        {
            ret = 1 + fun(pos + 1, state);
        }
        else
        {
            ll ret1 = 1 + fun(pos + 1, state + 1);
            ll ret2 = fun(pos + 1, state);
            ret = max(ret1, ret2);
        }
    }

    dp[pos][state] = ret;
    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    ll ans = 0, cnt;
    cin >> s;
    ll sz = (ll)s.size();

    for(int i = 0; i < sz; i++)
    {
        if(s[i] == 'a')
            ans = max(ans, 1 + fun(i + 1 , 0));
        else
            ans = max(ans, 1 + fun(i + 1, 1));
    }

    cout << ans << endl;
    //main();

}
