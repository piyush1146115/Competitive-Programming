#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, match, rem;

    while(scanf("%lld", &n) == 1){
        match = 0;
        rem = 0;
        while(n > 1){
            match += (n/ 2);
            rem = n % 2;
            n /= 2;
            n += rem;
        }
        cout << match << endl;
    }
    return 0;
}
