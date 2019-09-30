#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<long long int> q1, q2;
    long long int n, m, sum, test, cs = 0, c, i, j, s;

    scanf("%lld", &test);

    while(test--){
            sum = s = 0;

        scanf("%lld %lld", &n, &m);

        for(i = 0; i < n; i++)
        {
            scanf("%lld", &j);
            s += j;
            sum += j;
        }
        s -= j;

           for(i = 0; i < m; i++)
        {
            scanf("%lld", &j);
            s += j;
            sum += j;
        }
        sum -= j;

        printf("Case %lld: %lld\n",++cs, min(sum, s));
    }
    return 0;
}
