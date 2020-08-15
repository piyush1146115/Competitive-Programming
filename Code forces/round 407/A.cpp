#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k, ans = 0, m;

    scanf("%lld %lld",&n , &k);

    for(int i = 0; i < n; i++){
        scanf("%lld", &m);
        ans += (m / k);
        //cout << ans << endl;
        if(m % k != 0)
            ans++;
    }
    ans += (ans % 2);

    ans /= 2;

    printf("%lld\n",ans);
}
