#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long ans;
    long long i, j, ara[105], n;

    cin >> n;

    for(i = 1; i <= n; i++)
        cin >> ara[i];

    ans = ara[1];

    for(i = 2; i <= n; i++){
        ans +=(((ara[i] - 1) * i) + 1);
    }

    cout << ans << endl;
}
