#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, ans, mn;

    cin >> n >> m;

    mn = min(n , m);

    ans = (n + m)/3;

    ans = min(ans, mn);

    cout << ans << endl;

}
