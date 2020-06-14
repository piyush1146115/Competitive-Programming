#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int ara[10050];
vector <int> prime;
int main()
{
    long long int i, j, k, a, factor, sum, n;
    double temp;

    for(i = 4; i <= 10010; i += 2){
        ara[i] = 1;
    }

    for(i = 3; i <= 110; i += 2){
        if(ara[i] == 0){
            for(j = i * i; j <= 10050; j += i * 2){
                ara[j] = 1;
            }
        }
    }
   prime.pb(2);

    for(i = 3; i <= 10020; i += 2){
        if(ara[i] == 0){
            prime.pb(i);
        }
    }

    while(scanf("%lld", &n) == 1){
    a = n;

    sum = 1;

    for(i = 0; prime[i] <= sqrt(a); i++){
                factor = 0;
            if(a % prime[i] == 0){
            while(a % prime[i] == 0){
                factor++;
                a = a / prime[i];
            }
            temp = pow(prime[i], factor + 1);
            k = (temp - 1) / (prime[i] - 1);
            sum *= k;
          }
    }
    if(a > 1){
        temp = a * a;
        k = (temp -1)/ (a -1);
        sum = sum * k;
    }

    printf("Sum of divisors of %lld is %lld\n",n, sum);

    }
    return 0;
}

/**
int SOD( int n ) {
    int res = 1;
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            int tempSum = 1; //Contains value of (p^0+p^1+...p^a)
            int p = 1;
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                p *= prime[i];
                tempSum += p;
            }
            sqrtn = sqrt ( n );
            res *= tempSum;
        }
    }
    if ( n != 1 ) {
        res *= ( n + 1 ); //Need to multiply (p^0+p^1)
    }
    return res;
}
*/
