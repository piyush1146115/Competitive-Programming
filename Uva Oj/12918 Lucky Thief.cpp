#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, m, dif, test, temp;
    unsigned long long res;

    scanf("%lld",&test);
    while(test--){
    scanf("%lld %lld",&n, &m);
        dif = (m - n);
        res = 0;
        if(dif >= 0){
            res = n * dif;
            res += ((n - 1) * n) / 2;
        }
        else
        {
            dif = n - m;
            res += ((n - 1) * n) / 2;
            temp = (dif * (dif - 1)) / 2;
            res -= temp;
        }

        cout << res << endl;
    }
    return 0;
}
