#include<bits/stdc++.h>
using namespace std;
    int chk[5020];
int main()
{
    int cnt = 0, n, i, m;

    cin >> n;

    for(i = 0; i < n; i++){
        scanf("%d",&m);
        chk[m]++;
    }

    for(i = 1; i <= n; i++){
        if(chk[i] == 0)
            cnt++;
    }
    cout << cnt << endl;
}
