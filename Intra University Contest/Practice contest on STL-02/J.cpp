#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;

    while(scanf("%lld", &n) == 1){
        if(n == 0)
            break;

        long long a = 0, b = 0, cnt = 0, k = 1;

        while(k <= n){
            if(n & k){
                cnt++;
                if(cnt % 2 == 1){
                    a = a | k;
                }
                else{
                    b = b | k;
                }
            }
            k = k * 2;
        }

        printf("%lld %lld\n", a, b);
    }
}
