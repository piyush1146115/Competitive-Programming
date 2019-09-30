#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;

int main()
{
    int test, a, b, c, d, r,ara[550];
    long long int sum;
    scanf("%d",&test);

    while(test--){
        scanf("%d",&r);
        sum = 0;
        for(a = 0; a < r; a++){
            scanf("%d",&ara[a]);
        }
        sort(ara, ara + r);
        if(r % 2 == 0){
            c = r / 2;
        }
        else{
            c = (r + 1)/2;
        }

        for(a = 0; a < r; a++){
            sum += fabs(ara[a] - ara[c - 1]);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
