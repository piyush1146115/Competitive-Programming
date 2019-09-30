#include<bits/stdc++.h>
using namespace std;
int ara[550];
vector <int> prime;
int nd[10050];
#define pb push_back

void sieve()
{
    int i, j;
    prime.pb(2);
    ara[1] = 1;
    for(i = 4; i <= 500; i += 2)
    ara[i] = 1;

    for(i = 3; i <= 30; i += 2){
        if(ara[i] == 0){
            for(j = i * i; j <= 500; j += i * 2)
            {
                ara[j] = 1;
            }
        }
    }

    for(j = 3; j <= 150; j += 2)
    if(ara[j] == 0)
        prime.pb(j);
}

void nod()
{
    int i, j , k, sum, cont, num;

    for(i = 1;i <= 10005; i++ ){
            k = sqrt(i);
            sum = 1;
            num = i;
        for(j = 0; prime[j] <= k; j++){
                cont = 0;
            while(num % prime[j] == 0){
                num /= prime[j] ;
                cont++;
            }
            sum *= (cont + 1);
        }
        if(num > 1)
            sum *= 2;
        nd[i] = sum;
    }
}

int main()
{
    sieve();
   nod();

   int i, j, k, test;

   scanf("%d", &test);

   while(test--){
    int  l, r;
    scanf("%d %d",&l, &r);
    k = 0;
    for(i = l; i <= r; i++){
        if(ara[nd[i]] == 0){
            if(k == 1)
                printf(" ");

            printf("%d",i);
            k = 1;
        }
    }
    if(k == 0)
        printf("-1");

    printf("\n");
   }
   return 0;
}
