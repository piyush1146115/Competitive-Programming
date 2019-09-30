#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long l, z, i, m, c, temp, t = 0;
    map <long long , long long> mp;

    while(scanf("%lld %lld %lld %lld", &z, &i, &m, &l) == 4){
        if(!z && !i && !m && !l)
            break;
            t++;
            c = 0;
        while(mp[l] <= 1){
                 mp[l]++;
                c++;
            temp = (((l % m) * (z % m)) + (i % m)) %m;
                l = temp;
        }
        c = c / 2;
        printf("Case %lld: %lld\n",t, c);
         mp.clear();
    }
    return 0;
}
