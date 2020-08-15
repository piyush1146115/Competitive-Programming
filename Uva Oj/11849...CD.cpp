#include<bits/stdc++.h>
using namespace std;
int main()
{
    map <long long int, int> m;
    long long p, q, i, j, a;

    while(cin >> p >> q){
        if(p == 0 && q == 0)
            break;

        for(i = 0; i < p; i++){
            scanf("%lld",&j);
            m[j]++;
        }
        long long c = 0;
        for(i = 0; i < q; i++){
            scanf("%lld",&j);
            if(m[j] > 0)
                c++;
        }

        printf("%lld\n",c);
        m.clear();
    }
    return 0;
}
