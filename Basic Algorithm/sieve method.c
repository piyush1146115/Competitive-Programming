#include<stdio.h>
#include<math.h>
unsigned long long int ara[100000000], primes[10000000];
int main()
{
unsigned long long int n,a, b,i,c = 0;

scanf("%llu", &n);
for(a = 0; a < n; a++)
{
    ara[a] = 0;
}

b= sqrt(n);
for(a = 2; a  <= b; a++){
    if(ara[a] == 0){
        for(i = a*a;i < n; i+=a){
            ara[i] = 1;
        }
    }
}
for(i = 2; i < n; i++){
    if(ara[i] == 0){
        primes[c] = i;
        c++;
    }
}

for(a = 0; a < c; a++){
    printf("%llu ",primes[a]);
}
return 0;
}

