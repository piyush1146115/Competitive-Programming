#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll power(ll b, ll p)
{
    if(p == 0)
        return 1;
    if(p% 2 == 0){
        ll ret = power(b, p/2) % mod;
        return ((ret %mod) * (ret % mod)) % mod;
    }
    else{
        return ((b % mod) * (power(b, p - 1) % mod)) % mod;
    }
}

int main()
{
    string s;

    ll cnt = 0;

    cin >> s;

    ll ans = 0, b = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'b'){
            ans += (power(2, cnt));
            ans %= mod;
            b++;
        }
        if(s[i] == 'a')
            cnt++;
    }
    cout << ans - b  << endl;
}
