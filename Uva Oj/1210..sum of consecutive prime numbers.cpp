#include<bits/stdc++.h>
using namespace std;
int ara[10005];
int ind[10005];
vector <int> prime;
void sieve()
{
    int i, j, k = 0;

    ind[2] = 0;
    prime.push_back(2);
    k = 0;

    for(i = 4;i <= 10000; i += 2)
        ara[i] = 1;

    for(i = 3; i <= 105; i+= 2){
        if(ara[i] == 0){
            for(j = i * i; j <= 10000; j += (i + i))
                ara[j] = 1;
        }
    }

    for(i = 3; i <= 10000; i += 2){
        if(ara[i] == 0){
            prime.push_back(i);
            k++;
        }
        ind[i] = k;
        ind[i + 1] = k;
    }
}
int main()
{
    sieve();
    int n, i, cont, sum, po1, po2;

    while(scanf("%d",&n) == 1 && n != 0){

        po1 = ind[n];
        po2 = ind[n] - 1;
        cont = 0;
        while(po2 >= 0){
                sum = 0;
            for(i = po1; i >= po2; i--){
                sum += prime[i];
            }
            //printf("%d %\n",sum, cont);
            if(sum == n)
                cont++;
            else if(sum > n)
                po1--;

            po2--;
        }
        if(ara[n] == 0)
            cont++;

        printf("%d\n",cont);
    }
    return 0;
}
