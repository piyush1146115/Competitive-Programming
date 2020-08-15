#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, sum, i, j , num, den;

    while(scanf("%lld", &n) == 1){
        sum = 0;

        for(i = 1; ; i++){
            sum += i;
            if(sum == n){
                if(i % 2 == 0){
                    num = i;
                    den = 1;
                    break;
                }
                else{
                    num = 1;
                    den = i;
                    break;
                }
            }
            if(sum > n){
                if(i % 2 == 0){
                    den = (sum - n) + 1;
                    num = (i - den) + 1;
                }
                else{
                    num = (sum - n) + 1;
                    den = (i - num) + 1;
                }
                break;
            }
        }
        printf("TERM %lld IS %lld/%lld\n",n, num, den);
    }
    return 0;
}
