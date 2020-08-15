#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
vector <long long int> prime;
int ara[1000000];
long long int lis[50000];
long long int primeFactorize(long long int n)
{

    long long int i, k = 0;

    for(i = 0; prime[i] <= sqrt(n); i++){
        if(n % prime[i] == 0){
            while(n % prime[i] == 0){
                n = n / prime[i];
                lis[k++] = prime[i];
            }
        }
    }

    if(n > 1){
        lis[k++] = n;
    }

    return k;

}

int main()
{
    long long int a, b, c, n, i, siz;
    long long int primeFactorize(long long int n);

    prime.push_back(2);
    for(a = 3; a <= 220; a += 2){
        if(ara[a] == 0){
                prime.push_back(a);
            for(b = a*a; b <= 48000; b += 2*a){
                ara[b] = 1;
            }
        }
    }

    for(a = 219; a <= 48000; a += 2){
        if(ara[a] == 0){
        prime.push_back(a);
        }
    }

    while(scanf("%lld",&n) == 1 && n != 0){

        siz = primeFactorize(abs(n));
    printf("%lld =",n);
    if(n < 0){
        printf(" -1 x");
    }

    for(a = 0; a < siz; a++){
        if (a == siz - 1)
        printf(" %lld",lis[a]);
    else
        printf(" %lld x", lis[a]);
    }
    printf("\n");

    }
    return 0;
}
