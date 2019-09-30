#include<bits/stdc++.h>
using namespace std;
long long ara[20000005];
int main()
{
    long long int n, a, b ,i, j, k;
    vector <long long int> twin;
    for(a = 3; a <= 5000; a += 2 )
    {
        if(ara[a] == 0)
        {
            for(b = a*a ; b <= 20000000; b += 2*a)
            {
                ara[b] = 1;
            }
        }
    }

    for(a = 3; a <= 20000000 - 2; a += 2 ){
        if(ara[a+ 2] == 0 && ara[a] == 0){
            twin.push_back(a);
        }
    }

    while(scanf("%lld",&n) == 1){
        printf("(%lld, %lld)\n",twin[n -1], twin[n - 1] + 2);
    }
    return 0;
}

