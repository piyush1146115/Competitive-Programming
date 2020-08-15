#include<bits/stdc++.h>
using namespace std;
#define s(n) n*n
int main()
{
    long long a, b, c, i, cse = 0, test;
    scanf("%lld", &test);

    while(test--){
        scanf("%lld %lld %lld", &a, &b, &c);
        cse++;
        printf("Case %lld: ", cse);
        if((s(a) == s(b) + s(c)) || (s(b) == s(a) + s(c)) || (s(c) == s(a) + s(b)))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
