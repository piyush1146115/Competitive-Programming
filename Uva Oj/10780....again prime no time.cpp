#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int ara[100100];
vector <int> prime;

void sieve()
{
    int i, j;

    prime.pb(2);

    for(i = 3; i <= 110; i += 2){
        if(ara[i] == 0){
            for(j = i * i; j <= 10100; j++){
                ara[j] = 1;
            }
        }
    }

    for(i = 3; i <= 10050; i += 2){
        if(ara[i] == 0){
            prime.pb(i);
        }
    }
}

int main()
{
    sieve();

    int m, n, sum = 0, count ;
    int i, j, k, a, b, flag, temp, caseno = 0, test;

    scanf("%d", &test);

    while(test--){
            scanf("%d %d", &m, &n);

            temp = 10000000;
     for(i = 0; prime[i] <= m;i++){
            count = 0;
            sum = 0;
            if(m % prime[i] == 0){
                b = m;

            while(b % prime[i] == 0){
                b = b / prime[i];
                count++;
                }

                 k = prime[i];
                 a = 1;

            while(a != 0){
                a = n / k;
                if(a == 0)
                    break;
                sum += a;
                k *= prime[i];
            }
            sum = sum / count;
             if(sum < temp)
            temp = sum;
        }

   }

    printf("Case %d:\n",++caseno);

    if(temp == 0 || temp == 10000000){
        printf("Impossible to divide\n");
    }
    else{
        printf("%d\n",temp);
    }
    }
    return 0;
}
