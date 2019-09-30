#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int ara[50];
    int test, n, a, sum, i, j;

    scanf("%d", &test);

    while(test--){
        scanf("%d",&n);
        sum = 0;
        for(a = 0; a < n; a++){
            scanf("%d",&ara[a]);
        }

        sort(ara,ara+n);

        for(a = 1; a < n; a++){
            i = ara[a] - ara[a - 1];
            sum = sum + i;
        }
        i = ara[a - 1] - ara[0];
        sum = sum + i;

        printf("%d\n",sum);
    }
    return 0;
}
