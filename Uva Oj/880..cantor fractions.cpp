#include<bits/stdc++.h>
using namespace std;


int main()
{

   long long n, den, num, sum;
   long long i, j;

    while(scanf("%lld",&n) == 1){

                j = sqrt(1 + (4 * 2 * n));
                i = (j - 1) / 2;

                sum = (i*i + i)/2;
                printf("%lld\n",sum);
                if(sum == n){
                    den = 1;
                    num = i;
                }
                else if(sum > n){
                    den = 1 + (sum - n);
                    num = i - (sum - n);
                }

        //printf("%lld/%lld\n",den, num);
    }
    return 0;
}
