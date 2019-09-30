#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long sum, n, i, j, test, cse = 0;

    scanf("%lld", &test);
    while(test--){
        scanf("%lld", &n);
        sum = 0;
        for(i = 1; i <= n; i++){
            scanf("%lld", &j);
            if(j >= 0)
                sum += j;
        }

        printf("Case %lld: %lld\n",++cse, sum);
    }
    return 0;
}
