#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b, n;

    while(scanf("%lld %lld %lld", &a, &b, &n) == 3 && (a != 0 || b != 0 || n!= 0))
    {
        n = n % 5;

        if(n == 0)
            cout<<a<<endl;
        else if(n == 1)
            cout<<b<<endl;
        else if(n == 2)
            cout<<(b+1)/a<<endl;
        else if(n == 3)
            cout<<(a+b+1)/(a*b)<<endl;
        else if(n == 4)
            cout<<(a+1)/b<<endl;
    }
return 0;
}
