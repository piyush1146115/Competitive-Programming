#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main()
{
    long long test, n, k;

    cin >> test;

    while(test--){
        cin >> n >> k;

        long long ans = 1;

        while(k > 0){
            if(k % 2 == 1){
                ans = ((ans%MOD) * (n % MOD))%MOD;
            }

            k /= 2;
            n = ((n%MOD) * (n%MOD))%MOD;
        }

        cout << ans << endl;
    }

}
