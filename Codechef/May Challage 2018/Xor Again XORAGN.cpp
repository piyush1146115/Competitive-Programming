#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;

    scanf("%d", &test);

    while(test--){
        int n;
        scanf("%d", &n);
        long long k;

        scanf("%lld", &k);
        long long ans = k*2;
        for(int i = 2; i <= n; i++){
            scanf("%lld", &k);
            ans ^= (k*2);
        }

        printf("%lld\n",ans);
    }

    return 0;
}
