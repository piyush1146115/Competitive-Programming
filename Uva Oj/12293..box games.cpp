#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;

    while(scanf("%lld", &n) == 1, n){
        n = (n+1) & n;
        if(n == 0)
            printf("Bob\n");
        else
            printf("Alice\n");
    }
    return 0;
}
