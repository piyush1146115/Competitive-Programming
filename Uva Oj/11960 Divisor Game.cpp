#include<bits/stdc++.h>
using namespace std;
#define MX 1000015
#define pb push_back
vector<int>prime;
bool ara[MX];
int divi[MX], res[MX];


void sieve()
{
    int i, j, k;
    prime.pb(2);

    for(i = 3; i <= 1010; i+= 2){
        if(ara[i] == false){
            for(j = i*i; j <= MX; j += i*2){
                ara[j] = true;
            }
        }
    }

    for(i = 3; i <= MX; i+= 2)
        if(ara[i] == false)
        prime.pb(i);
}


void divisor()
{
    int i, j, k, n, sum, mx = -1, res;

    for(i = 1; i <= MX; i++){
            sum = 1;
            n = i;

        for(j = 0; prime[j] <= sqrt(n); j++){
            k = 0;
            if(n % prime[j] == 0){
                while(n % prime[j] == 0){
                    k++;
                    n /= prime[j];
                }
            }
            sum *= (k + 1);
        }
        if(n > 1){
            sum *= 2;
        }

        if(sum >= mx){
            mx = sum;
            res = i;
        }
        divi[i] = res;
    }
}


int main()
{
    sieve();
    divisor();
    int test, n;

    scanf("%d", &test);

    while(test--){
    scanf("%d", &n);

    printf("%d\n",divi[n]);
    }
 return 0;
}
