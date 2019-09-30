#include<bits/stdc++.h>
using namespace std;
#define MX 1000005

bool isprime[MX];
long int phi[MX];

void toi()
{
    int i;
    memset(isprime, true, sizeof(isprime));
    isprime[1] = false;

    phi[1] = 1;
    phi[2] = 1;

    for(i = 4; i <= MX; i += 2){
        phi[i] = i/ 2;
        isprime[i] = false;
    }

     for( i = 3; i <= MX; i += 2){
        phi[i] = i;
    }

    for(i = 3; i <= MX/2 ; i+= 2)
    {
        if(isprime[i] == true){
            phi[i] = i -1;
            for(int j = i + i; j <= MX; j+= i){
                phi[j] -= (phi[j] / i );
                isprime[j] = false;
            }
        }
    }
}


int main()
{
    toi();
    int test, n;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        if(isprime[n]){
            printf("%d\n", n  - 1);
        }
        else
        printf("%ld\n",phi[n]);
    }
}
