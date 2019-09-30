#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, num, flag, a, b, i, temp;

    while(scanf("%lld", &n) && n != 0){
        a = b = 0;
        num = 1;
        flag = 1;
        for(i = 1; i < 32; i++){
                if(n & num){
                flag++;
                if(flag % 2 == 1){
                    a = a | num;
                }
                else{
                    b = b | num;
                }
                }
            num *= 2;
        }
        printf("%lld %lld\n",b, a);
    }
    return 0;
}
