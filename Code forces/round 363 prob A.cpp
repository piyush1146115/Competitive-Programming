#include<bits/stdc++.h>
using namespace std;
int ara[2000000];
int main()
{
    int n, i, ans = 1390790214, dif;
    string s;
    cin >> n >> s;

    for(i = 0; i < n; i++){
        scanf("%d", &ara[i]);
    }
    int flag = 1;
    for(i = 0; i < s.size() - 2; i++){
        if(s[i] == 'R' && s[i + 1] == 'L'){
            dif = ara[i + 1] - ara[i];
            flag = 0;
            ans = min(dif, ans);
        }
    }
    if(flag)
        cout << "-1" << endl;
    else
    cout << ans/2 << endl;

    return 0;
}
