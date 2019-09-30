#include<bits/stdc++.h>
using namespace std;

long long ara[10000050];

void calc()
{
    long long i, res;
    double x;

    for(i = 1; i <= 10000002; i++){
        x += log10(i);
        res = (int)x + 1;
        ara[i] = res;
    }
}

int main()
{
    ara[0] = 1;
    calc();
    int i, j, test, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        printf("%lld\n", ara[n]);
    }
    return 0;
}
