#include<bits/stdc++.h>
using namespace std;
long long ara[10005];
int main()
{
    long long a, b, n, i, j, k;
    i = 0;
    while(scanf("%lld", &n) == 1){

        ara[i++] = n;

       sort(ara,ara + i);
        j = i -1;
        if(j % 2 == 0){
            printf("%lld\n", ara[i / 2]);
        }
        else{
            b = (ara[j / 2] + ara[(j/ 2) + 1]) / 2;
            printf("%lld\n", b);
        }
    }
    return 0;
}
