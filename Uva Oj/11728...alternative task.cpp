#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int ara[10050];
vector <int> prime;
int Sod[100000];
void SOD(void)
{
      long long int i, j, k, a, factor, sum, n;
    double temp;

    for(i = 4; i <= 1050; i += 2){
        ara[i] = 1;
    }

    for(i = 3; i <= 50; i += 2){
        if(ara[i] == 0){
            for(j = i * i; j <= 1050; j += i * 2){
                ara[j] = 1;
            }
        }
    }
   prime.pb(2);

    for(i = 3; i <= 1020; i += 2){
        if(ara[i] == 0){
            prime.pb(i);
        }
    }

    n = 1001;

    for(n = 2; n <= 1000; n++){
     a = n;
     sum = 1;
    for(i = 0; prime[i] <= sqrt(a); i++){
                factor = 0;
            if(a % prime[i] == 0){
            while(a % prime[i] == 0){
                factor++;
                a = a / prime[i];
            }
            temp = pow(prime[i], factor + 1);
            k = (temp - 1) / (prime[i] - 1);
            sum *= k;
          }
    }
    if(a > 1){
        temp = a * a;
        k = (temp -1)/ (a -1);
        sum = sum * k;
    }
    Sod[sum] = n;
    }
}
int main()
{
    SOD();
  int n, casen = 0;

  while(scanf("%d",&n) == 1 && n != 0){
    printf("Case %d: ",++casen);
    if(Sod[n] > 0){
        printf("%d\n",Sod[n]);
    }
    else if(n == 1){
        printf("1\n");
    }
    else{
        printf("-1\n");
    }
  }
    return 0;
}


