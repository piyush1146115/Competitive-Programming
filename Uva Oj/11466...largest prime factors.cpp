#include<bits/stdc++.h>
using namespace std;
vector <long long int> prime;
int chk[10000050];
#define pb push_back
void sieve()
{
    prime.pb(2);
    int i, j;

    for(i = 3; i <= 3200; i++){
            if(chk[i] == 0){
        for(j = i * i; j <= 10000005; j += (i + i)){
            chk[j] = 1;
        }
        }
    }

    for(i = 3; i <= 10000005; i++)
        if(chk[i] == 0)
            prime.pb(i);
}

int main()
{
    sieve();
    set <long long> div;
    long long i, j, k, n, sq;

    while(scanf("%lld", &n) == 1 && n != 0){
        if(n < 1)
            n *= -1;
        k = n;
        div.clear();
            for(i = 0; prime[i] <= sqrt(n); i++){
                while(n % prime[i] == 0){
                    div.insert(prime[i]);
                    n/= prime[i];
                }
            }
            if(n > 1)
                div.insert(n);

        set <long long> :: iterator eit;
        if(div.size() < 2){
            printf("-1\n");
        }
        else{
            eit = div.end();
            eit--;
            if(*eit == k){
                printf("-1\n");
            }
            else{
            cout << *eit << endl;
            }
        }
    }
    return 0;
}
