#include<bits/stdc++.h>
using namespace std;
long long power(long long int b,long long int p)
{
    long long ans = 1;

    while(p){

    if(p & 1){
            ans *= b;
        }
        b *= b;
     p = p / 2;
    }
    return ans;
}
int main()
{
    long long  i, j, k, l, flag[205];
    long long cube , sum1, sum2, sum3, sum;

    for(i = 6; i <= 200; i++){
        cube = power(i, 3);
        for(j = 2; j <= 200; j++){
                sum1 = power(j, 3);
            for(k =j + 1; k <= 200; k++){
                sum2 = power(k , 3);
                for(l =k + 1; l <= 200; l++){
                    sum3 = power(l, 3);
                    sum = sum1 + sum2 + sum3;

                    if(sum == cube){
                        printf("Cube = %lld, Triple = (%lld,%lld,%lld)\n",i , j, k, l);

                            }
                    }
            }
        }
    }

    return 0;
}
