#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long test, n, i, cont, s, ans;
    map<long long, long long> mp;

    cin >> test;

    while(test--){
            cont = 0;
            scanf("%lld", &n);
        ans = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%lld", &s);
        mp[s]++;
        if(mp[s] > 1){
            ans = max(cont, ans);
            mp.clear();
            mp[s]++;
            cont = 0;
        }
            cont++;
    }

    cout << ans << endl;
    mp.clear();
    }
    return 0;
}
