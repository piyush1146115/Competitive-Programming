#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
#define pb(x) push_back(x)
bool chk[35000];
void sieve()
{
    int i, j;
    prime.pb(2);

    for(i = 3; i <= 200; i += 2){
            if(chk[i] == 0){
        for(j = i * i; j <= 32000; j += i << 1){
            chk[j] = 1;
        }
            }
    }

    for(i = 3; i <= 32000; i+= 2)
        if(!chk[i])
        prime.pb(i);

}
int  main()
{
    sieve();
    long long int n, low, high, i, j, c, sum;

    while(scanf("%lld %lld", &low, &high) == 2)
    {
        if(low == 0 && high == 0){
            break;
        }
        n = abs(high - low);
        sum = 1;

        for(i = 0; prime[i] <= sqrt(n); i++){
            c = 0;
            if(n % prime[i] == 0){
                while(n % prime[i] == 0){
                    c++;
                    n /= prime[i];
                }
                sum *= (c + 1);
            }
        }
        if(n > 1){
            sum *= 2;
        }

        cout << sum << endl;
    }
    return 0;
}
