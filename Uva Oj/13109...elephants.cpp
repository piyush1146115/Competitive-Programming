#include<bits/stdc++.h>
using namespace std;
long long ara[100010];
int main()
{
    long long test, m, n, i, s;
    cin >> test;

    while(test--){
        cin >> m >> n;
        for(i = 0; i < m; i++){
            scanf("%lld", &ara[i]);
        }
        sort(ara, ara + m);
        s = 0;
        for(i = 0; i < m; i++){
            s += ara[i];
            if(s > n)
                break;
        }
        cout << i << endl;
    }
    return 0;
}
