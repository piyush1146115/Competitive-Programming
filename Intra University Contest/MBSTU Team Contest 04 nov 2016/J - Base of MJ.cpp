#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n, d, test, tc = 0;

    cin >> test;

    while(test--){
        cin >> n >> d;

        printf("Case %llu: %llu\n",++tc,(n - 1)/d);
    }
}
