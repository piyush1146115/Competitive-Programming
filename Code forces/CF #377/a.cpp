#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b, k, n;

    scanf("%lld %lld", &a, &k);
    int ans = 0, c = 1;
    n = a;
    while(1){
            c++;
        ans++;
         if(n % 10 == 0)
            break;

         b = n % 10;

         if(b  == k)
            break;


        n = a * c;

    }

    cout << ans << endl;
}
