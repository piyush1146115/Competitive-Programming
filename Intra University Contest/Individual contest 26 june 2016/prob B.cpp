#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k, i;

    cin >> n >> k;
    if(k > 0){
    for(i = 1; i < n - k; i++)
        printf("%lld ", i);
    for(i = n; i >= n - k; i--)
        printf("%lld ",i);
    }
    else
        {
            for(i = 1; i <= n; i++)
                printf("%lld ",i);
        }



    printf("\n");
}
