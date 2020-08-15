#include<stdio.h>
long long int ara[1000005];

int main()
{
    long long int a, b, n, test, n1, n2, i, j, sum, count;
    ara[1] = 1;


    for(a = 3; a <= 1000; a += 2){
            if(ara[a] == 0){
             for(b = a * a; b <= 1000000; b += a * 2){
                ara[b] = 1;
             }
        }
    }
  /*  for(i = 1; i <= 100; i++)
        if(ara[i] == 0)
            if(i == 2 || i % 2 != 0)
            printf("%lld ",i);
*/
    scanf("%lld",&test);

    while(test--){
        scanf("%lld %lld", &n1, &n2);
        count = 0;
        if(n1 == 2 || n2 == 2)
            count++;

        if(n1 % 2 == 0){
            n1++;
        }

        for(i = n1; i <= n2; i += 2 ){
            j = i;
            sum = 0;
            if(ara[j] == 0){

            while(j != 0){
                sum += j % 10;
                j =j / 10;
            }
            //printf("%lld ", sum);
            if(ara[sum] == 0){
                if(sum == 2 || sum % 2 != 0)
                count++;
                }
            }
        }
        printf("%lld\n",count);
    }


    return 0;

}

