#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k, i, j, co = 0, ans;

    cin >> n >> k;

    //j = 5 - k;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &m);

        if(m + k <= 5)
            co++;
    }
    ans = co / 3;

    cout << ans << endl;

}
