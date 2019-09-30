#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;

    cin >> n;

    if(n < 9){
        printf("1\n%lld\n",n);
    }
    else if( n % 10 == 0){
        printf("2\n");
    }
    else{
        printf("1\n%lld\n",n % 10);
    }

    return 0;
}
