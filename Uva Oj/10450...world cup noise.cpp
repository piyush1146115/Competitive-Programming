#include<bits/stdc++.h>
using namespace std;

unsigned long long int b[100];
unsigned long long bee(unsigned long long int n)
{
    if(n == 1){
        return 2;
    }
    if(n == 2){
        return 3;
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
    int test, i;

    scanf("%d", &test);

    for(i = 1; i <= test; i++){
        scanf("%llu", &n);

        printf("Scenario #%d:\n", i);
        printf("%llu\n\n",bee(n));
    }
    return 0;
}
