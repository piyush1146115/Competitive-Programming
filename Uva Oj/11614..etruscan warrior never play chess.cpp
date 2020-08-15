#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long long int a, b, n, sum;
    int test;

    scanf("%d",&test);

    while(test--){
        scanf("%llu",&n);
        //b = sqrt(n);
        sum = (sqrt(1+8*n)-1)/2;
        /*for(a = b + 1; a < n; a++){
            sum += a;
            if(sum > n){
                break;
            }
        }*/
        printf("%llu\n",sum);
    }
    return 0;
}
