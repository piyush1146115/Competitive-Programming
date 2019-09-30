#include<bits/stdc++.h>
using namespace std;

vector <int> prime;
int ara[50000];
void sieve()
{
    int i, j, k;

    prime.push_back(2);

    for(i = 3; i <= 217; i+= 2){
        if(ara[i] == 0){
            for(j = i * i; j <= 47000;j += (i+i)){
                ara[j] = 1;
            }
        }
    }

    for(i = 3; i <= 47000; i+= 2)
        if(ara[i] == 0)
        prime.push_back(i);

}
bool isPrime(long long n)
{
    int sqr, i;

    if(n == 1)
        return false;

    sqr = sqrt(n);
    for(i = 0; prime[i] <= sqr; i++){
        if(n % prime[i] == 0)
            return false;
    }
    return true;
}

int main()
{
    sieve();
    long long l, u, i, flag, cont, dis, minfir, maxfir, mindis, maxdis, fir, sec;

    while(scanf("%lld %lld",&l, &u) == 2){
        cont = 0;
        mindis = 10000000;
        maxdis = -1;
        flag = 0;
        if(l == 1)
            l++;

        if(l == 2){
        fir = 2;
        cont = 1;
        flag = 1;
        }
        if(l % 2 == 0)
            l++;

        for(i = l; i <= u; i+= 2){
            if(isPrime(i)){
                   // printf("%lld\n", i);
                cont++;
                if(flag == 0)
                fir = i;
                flag = 1;
                if(cont >= 2){
                     sec = i;
                    dis = sec - fir;
                    fir = sec;
                   // printf("%lld %lld %lld\n",fir, sec, dis);
                    if(dis < mindis){
                        minfir = sec;
                        mindis = dis;
                    }
                    if(dis > maxdis){
                        maxfir = sec;
                        maxdis = dis;
                    }
                }
            }
        }
        if(cont < 2)
        {
            printf("There are no adjacent primes.\n");
        }
        else{
        printf("%lld,%lld are closest, ",minfir - mindis, minfir);
        printf("%lld,%lld are most distant.\n", maxfir - maxdis, maxfir);
    }
    }
    return 0;
}

