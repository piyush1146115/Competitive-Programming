#include<bits/stdc++.h>
using namespace std;
long long cat[25];

void catalan()
{
    long long i;
    cat[0] = 1;

    for(i = 1; i <= 20; i++){
        cat[i] = 2 *  (2 * i + 1) * cat[i  - 1];
        cat[i] /= (i + 2);
    }
}

int main()
{
    catalan();
    long long i, n, j;

while(scanf("%lld", &n) == 1){
    for(i = 1; i <= n; i++){
        if(cat[i] > n){
            printf("%lld\n",i);
            break;
        }
    }
}

return 0;
}
