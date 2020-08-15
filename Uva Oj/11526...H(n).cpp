#include<bits/stdc++.h>
using namespace std;
long long H(int n){
    long long res = 0, i = 1, j = 2;

    j = n / 2;
    for(i = j;i >= 1; i--)
        res += (n / i);

    res += (n - j);
    return res;
}
int main()
{
    int n, test;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        printf("%lld\n",H(n));
    }

    return 0;
}
