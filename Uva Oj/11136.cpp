#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, b, k, i, res;
    multiset <long long int> s;
    multiset <long long int> :: iterator bit, eit;

    while(scanf("%lld", &n) == 1 && n != 0){
            res = 0;
        while(n--){
            scanf("%lld",&k);
            while(k--){
                scanf("%lld", &b);
                s.insert(b);
            }
            bit = s.begin();
            eit = s.end();
            eit--;
            res += ((*eit) - (*bit));
            s.erase(eit);
            s.erase(bit);
        }
        printf("%lld\n", res);
        s.clear();
    }
    return 0;
}
