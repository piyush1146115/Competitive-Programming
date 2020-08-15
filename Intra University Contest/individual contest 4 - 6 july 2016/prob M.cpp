#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long llx, lly, urx, ury, r, c, test, n, cse = 0;

    scanf("%lld" ,&test);
    while(test--){
        cse++;
        scanf("%lld %lld %lld %lld",&llx, &lly, &urx, &ury);
        printf("Case %lld:\n", cse);
        scanf("%lld", &n);
        while(n--){
            scanf("%lld %lld", &r, &c);
            if((r >= llx &&  r <= urx) && (c >= lly && c <= ury))
                printf("Yes\n");
            else
                printf("No\n");
        }

    }
return 0;
}
