#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d, e;
    long long res;

    while(scanf("%d %d %d %d %d",&a ,&b, &c, &d, &e) == 5 && (a != 0 || b != 0 || c!= 0 || d != 0 || e != 0)){
        res = a * b * c * (d * d) * (e * e);

        printf("%lld\n",res);
    }

    return 0;
}
