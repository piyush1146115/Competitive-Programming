#include<bits/stdc++.h>
using namespace std;

long long power(int b, int p)
{
    long long ans = 1;

    while(p){

    if(p & 1){
            ans *= b;
        }
        b *= b;
     p = p / 2;
    }
    return ans;
}

int main()
{
    int n, p;

    while(scanf("%d %d", &n, &p) == 2){

    printf("%lld\n",power(n , p));
    }
    return 0;
}
