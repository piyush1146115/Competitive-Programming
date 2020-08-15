#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara[100], m, n, i, dif = 10000000, j;

    cin >> m >> n;

    for(i = 0; i < n; i++)
        scanf("%d", &ara[i]);

    sort(ara, ara + n);

    for(i = 0; i <= n-m ; i ++){
            int d = fabs(ara[i] - ara[i + m - 1]);
            dif = min(d, dif);
    }

    cout << dif << endl;

    return 0;
}
