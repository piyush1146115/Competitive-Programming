#include<bits/stdc++.h>
using namespace std;
vector <int> prime;
int indx[10000005];
int ara[10000005];
void sieve()
{
    int i, j, k, cont = 0;

    prime.push_back(2);
    indx[1] = 0;
    indx[2] = 0;

    for(i = 3; i <= 10000; i += 2){
        if(ara[i] == 0){
            for(j = i * i; j <= 10000000; j += (i + i)){
                ara[j] = 1;
            }
        }
    }

    for(i = 3; i <= 10000000; i += 2){
        if(ara[i] == 0){
            prime.push_back(i);
            cont++;
        }
        indx[i] = cont;
        indx[i + 1] = cont;
    }
}
int main()
{
    sieve();
    int n, i, j;

    while(scanf("%d",&n) == 1, n){
        if(n == 2){
            printf("0\n");
        }
        else if(ara[n] == 0 && n % 2 != 0)
            printf("0\n");
        else{
            i = indx[n];
            printf("%d\n",prime[i + 1] - prime[i]);
        }
    }
    return 0;
}
