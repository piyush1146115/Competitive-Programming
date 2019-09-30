#include<bits/stdc++.h>
using namespace std;

unsigned long long int b[100];
unsigned long long bee(unsigned long long int n)
{
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    if(b[n] == 0){
        b[n] = bee(n - 1) + bee(n -2);
        return b[n];
    }
    else{
        return b[n];
    }
}
int main()
{
    unsigned long long int n;

    while(scanf("%llu", &n) == 1 && n != 0){
        printf("%llu\n", bee(n));
    }
    return 0;
}
