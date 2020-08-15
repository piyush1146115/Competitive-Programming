#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, i, cse = 0, cont, test;

    scanf("%lld", &test);

    while(test--){
        scanf("%lld",&n);
        cont = 0;

        while(n != 0){
            i = n % 2;
            n = n / 2;
            if(i == 1)
                cont++;
        }
        cse++;

        if(cont % 2 == 0)
            printf("Case %lld: even\n", cse);
        else
            printf("Case %lld: odd\n",cse);
    }
    return 0;
}
