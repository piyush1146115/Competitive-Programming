#include<math.h>
#include<stdio.h>
int main()
{
    long long int a, b, n, num, i, j, k, prime, x, y;

    while(scanf("%lld",&n) == 1){
        num = 0;
        a = n * 2;
        printf("%lld\n",a);

        b = n;
        while(b >= 1){
            i = b % 10;
            num = num * 10 + i;
            b = b/10;
        }
        //printf("%lld", num)
        if(num == n){
                prime = 0;
            j = sqrt(num);
            for(x = 2; x <= j;x++){
                if(num % x == 0){
                    prime = 1;
                    break;
                }
            }
            if(prime == 0){
                break;
            }
        }
    }
return 0;
}
