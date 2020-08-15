#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, i, j, a, b;

    while(scanf("%lld", &n) == 1, n){
            j = 1;
        for(i = 1; i <= n; i++){
                if(i == 1)
            scanf("%lld", &a);
        else{
                scanf("%lld", &b);
                a= a ^ b;
        }
        }
        if(a)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
