#include<bits/stdc++.h>
using namespace std;

long long int f(long long n)
{
    if(n == 0)
        return 0;

    if(n % 10 != 0)
        return n % 10;

    else
        return f(n / 10);
}

int main()
{
    long long int i, j, a, b, sum;

    while(scanf("%lld %lld", &i, &j) && (i >= 0 || j >= 0)){
            sum = 0;

            for( a = i; a <= j; a++){

                sum += f(a);
            }

            printf("%lld\n", sum);
    }
    return 0;
}
