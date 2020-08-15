#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
long long ara[2000005];
int main()
{
    long long int n, a, b,temp;

    while(scanf("%lld", &n) == 1 && n != 0)
    {
        for(a = 0; a < n ; a++)
        {
            scanf("%lld",&ara[a]);
        }

        /*for(a = 0; a < n - 1; a++){
            for(b = a + 1; b < n; b++){
                if(ara[b] < ara[a]){
                    temp = ara[a];
                    ara[a] = ara[b];
                    ara[b] = temp;
                }
            }
        }*/
        sort(ara,ara+n);
        for(a = 0; a < n-1; a++)
        {
            printf("%lld ",ara[a]);
        }
        printf("%lld",ara[n-1]);
        printf("\n");
    }
    return 0;
}
