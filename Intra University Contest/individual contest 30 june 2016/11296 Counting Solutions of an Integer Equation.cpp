#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long m, ans, n;

    while(cin >> m){
            n = m / 2;
        ans = ((n + 1) * (n + 2))/ 2;
        cout << ans << endl;
    }
    return 0;
}
