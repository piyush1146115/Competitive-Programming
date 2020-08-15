/*#include<bits/stdc++.h>
using namespace std;
long long int PF[105], MPF[105];

long long int power(long long int b, long long int p)
{
   long long int ans = 1;

    while(p){

    if(p & 1){
            ans *= b;
        }
        b *= b;
     p = p / 2;
    }
    return ans;
}

long long int gcd(long long int a,long long int b){ return b ? gcd(b, a % b) : a; }

int main()
{
   long long int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    long long int test, N, n, i, j, k, ara[15], LCM, sum, caseno = 0;

    scanf("%lld", &test);

    while(test--){
        memset(PF, 0, sizeof(PF));
        memset(MPF, 0, sizeof(MPF));

        LCM = 1;
        sum = 0;
        scanf("%lld", &N);

        for(i = 0; i < N; i++)
            scanf("%lld", &ara[i]);

        for(i = 0; i < N; i++){
            n = ara[i];
            for(j = 0; prime[j] <= sqrt(n); j++ ){
                if(n % prime[j] == 0){
                    while(n % prime[j] == 0){
                        n = n / prime[j];
                        PF[prime[j]]++;
                    }
                    if(MPF[prime[j]] < PF[prime[j]]){
                        MPF[prime[j]] = PF[prime[j]];
                    }
                    PF[prime[j]] = 0;
                }
            }
             if(n > 1){
                PF[n]++;
                if(MPF[n] < PF[n]){
                    MPF[n] = PF[n];
                }
                PF[n] = 0;
            }
        }

            for(i = 2; i <= 101; i++){
                if(MPF[i] > 0){
                    LCM *= power(i, MPF[i]);
                }
            }

             for(i = 0; i < N; i++){
                sum += (LCM / ara[i]);
            }



            k = gcd(LCM, sum);

            sum = sum / k;
            LCM = LCM / k;


            printf("Case %lld: %lld/%lld\n",++caseno, LCM * N, sum);
        }
        return 0;
}
*/
#include <cstdio>
long long n, v[16];
long long gcd(long long a, long long b){ return b ? gcd(b, a % b) : a; }
void simplify(long long &num, long long &den){
    long long g = gcd(num, den);
    num /= g;
    den /= g;
}
int main(void){
    int t; scanf("%d", &t);
    for(int cnum = 0; cnum++ < t && scanf("%lld", &n) == 1; ){
        long long den = 1, num = 0;
        for(int i = 0; i < n; ++i){
            scanf("%lld", v + i);
            den = (den / gcd(den, v[i])) * v[i];
        }
        for(int i = 0; i < n; ++i) num += den / v[i];
        simplify(num, den);
        simplify(num, n);
        printf("Case %d: %lld/%lld\n", cnum, n * den, num);
    }
    return 0;
}


