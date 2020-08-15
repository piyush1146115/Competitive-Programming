#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, a, b, s, sum;

    cin >> n;

    while(n--){
        cin >> a >> b;
        s = a + b + 1;
        sum = (s * (s + 1)) / 2;
        printf("%lld\n",sum - b);
    }
    return 0;
}
