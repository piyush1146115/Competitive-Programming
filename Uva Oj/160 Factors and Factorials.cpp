#include<bits/stdc++.h>
using namespace std;
vector <int> prime;
int ara[105];
void sieve()
{
    int i, j,k ;
    for(i = 3; i <= 10; i+= 2){
            if(ara[i] == 0)
        for(j = i * i; j <= 100; j += (i * 2)){
            ara[j] = 1;
        }
    }
    prime.push_back(2);

    for(i = 3; i <= 100; i+= 2)
    if(ara[i] == 0){
        prime.push_back(i);
        //cout << i << endl;
    }
}
int main()
{
    sieve();
    int i, j, n, k, c, tem;
    int factors[105];

    while(scanf("%d",&n) == 1 && n != 0){
        memset(factors, 0, sizeof(factors));


        for(i = 2; i <= n; i++){
                tem = i;
            for(k = 0; prime[k] <= sqrt(tem);k++ ){
                    c = 0;
                while(tem % prime[k] == 0){
                    tem/= prime[k];
                    c++;
                }
               // cout << prime[k] <<" " <<  tem << " " << c << endl;
                factors[prime[k]] += c;
            }
            if(tem > 1)
                factors[tem] += 1;

        }
        sort(factors, factors + 100);
        printf("%3d! =", n);
        c = 0;
        for(i = 99; i >= 0; i--){
            if(factors[i] == 0)
                break;
                 c++;
            if(c == 16){
                printf("\n      ");
                c = 0;
            }
            printf("%3d",factors[i]);

        }
        printf("\n");
    }
    return 0;
}
