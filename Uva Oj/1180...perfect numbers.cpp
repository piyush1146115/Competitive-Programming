#include<bits/stdc++.h>
using namespace std;
vector <int>prime;
int ara[100000];

unsigned long long power(int b, int p)
{
    unsigned long long ans = 1;

    while(p){

    if(p & 1){
            ans *= b;
        }
        b *= b;
     p = p / 2;
    }
    return ans;
}

void sieve()
{
    int i, j, k;

    for(i = 3; i <= 305; i += 2){
        if(ara[i] == 0){
            for(j = i * i; j <= 93000; j += i * 2){
                ara[j] = 1;
            }
        }
    }
   prime.push_back(2);

    for(i = 3; i <= 93000; i += 2){
        if(ara[i] == 0){
            prime.push_back(i);
        }
    }
}

int main()
{
    sieve();
    unsigned long long num, perfNum, a, k, temp, sum;
    int i, j, factor, test, n;

    scanf("%d", &test);

    while(test--){

        if(test)
        scanf("%d,", &n);
        else
        scanf("%d", &n);

        a = power(2, n);
        num = (a - 1) *(a / 2);
        a = num;

        sum = 1;
        //printf("a = %d\n", a);
    for(i = 0; prime[i] <= sqrt(a); i++){
                factor = 0;
            if(a % prime[i] == 0){
            while(a % prime[i] == 0){
                factor++;
                a = a / prime[i];
            }
            temp = power(prime[i], factor + 1);
            k = (temp - 1) / (prime[i] - 1);
            sum *= k;
          }
    }
    if(a > 1){
        temp = a * a;
        k = (temp -1)/ (a -1);
        sum = sum * k;
    }

    sum = sum - num;


    if(sum == num){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    }
return 0;
}
