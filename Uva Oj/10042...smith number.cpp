#include<bits/stdc++.h>
using namespace std;
long long int ara[35005];
vector <long long int> prime;
void sieve()
{
   long long  int i, j, k;

    prime.push_back(2);

    for(i = 3; i <= 190; i += 2){
        if(ara[i] == 0){
            for(j = i * i; j <= 35000; j += 2 * i){
                ara[j] = 1;
            }
        }
    }

    for(i = 3; i <= 35000; i += 2)
        if(ara[i] == 0)
        prime.push_back(i);
}

long long int factorSum(long long int n)
{
  long long int sum = 0, i, j, k, flag = 0;


   for(i = 0; prime[i] <= sqrt(n); i++){
        if(n % prime[i] == 0){

            flag = 1;
            while(n % prime[i] == 0){
                n = n / prime[i];
                 //printf("%d\n",n);
                j = prime[i];
                while(j != 0){
                    k = j % 10;
                    j = j/10;
                    sum += k;
                }
            }
        }
   }
   if(n > 1 && flag == 1){
       j = n;
        while(j != 0){
            k = j % 10;
            j = j/10;
            sum += k;
   }

}
 return sum;
}

int main()
{
    sieve();
    //freopen("input.txt", "rt", stdin);

   long long int m, n, i, test, sum, j, k;

    //printf("%d\n", factorSum(4));
    scanf("%lld", &test);

    while(test--){
        scanf("%lld", &m);

    for(i = m + 1; ;i++){
        n = i;
     k = factorSum(n);
    sum = 0;
    while(n != 0){
        j = n % 10;
        sum += j;
        n = n / 10;
    }
    if(k == sum){
        printf("%lld\n",i);
        break;
    }

}
}
return 0;
}
