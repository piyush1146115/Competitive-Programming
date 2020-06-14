#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long y, k, n, x;

    cin >> y >> k >> n;

    long long next = k * ((y/k) + 1LL);

    if(next > n){
        cout << -1 << endl;
    }
    else{
        for(;next <= n; next += k){
            x = next - y;
            cout << " " << x;
        }
        cout << endl;
    }

}
