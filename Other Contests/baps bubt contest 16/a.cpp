#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b, c, n, k, test, cs = 0;

    cin >> test;

    while(test--){
        scanf("%lld %lld", &k, &n);
        if(k == 0){
        a = n / 3;
        b = (n * 4) / 9;
        c = (n * 2)/ 9;
        printf("Case %lld:\n%lld\n%lld\n%lld\n", ++cs, a, b, c);
        }
        else{
            a = (n * 9)/ 2;
            b = a / 3;
            c = (a * 4)/ 9;
            printf("Case %lld:\n%lld\n%lld\n%lld\n", ++cs, b, c, a);
        }


    }
return 0;
}
