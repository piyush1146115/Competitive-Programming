#include<bits/stdc++.h>
using namespace std;
vector <long long int> prime;
int chk[32005];
#define pb push_back
long long power(long long b, long long p)
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

void sieve()
{
    long long int i, j;

    prime.pb(2);

    for(i = 3; i <= 180; i += 2){
            if(chk[i] == 0){
        for(j = i * i; j <= 32000; j += i << 2){
           chk[j] = 1;
        }
    }
    }

    for(i = 3; i <= 32000; i += 2)
        if(chk[i] == 0)
        prime.pb(i);
}
int main()
{
    sieve();
    long long n, ans, temp, i, j, c;

    while(scanf("%lld", &n) && n != 0){
        ans = 1;

        for(i = 0; prime[i] <= sqrt(n); i++){
            if(n % prime[i] == 0){
                c = 0;
                while(n % prime[i] == 0){
                    c++;
                    n /= prime[i];
                }
                ans *= power(prime[i], c - 1);
                ans *= (prime[i] - 1);
            }
        }
        if(n > 1){
            ans *= (n - 1);
        }
        cout << ans << endl;
    }
    return 0;
}
