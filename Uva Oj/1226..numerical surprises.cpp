#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long test, n, i, j, k, ans;
    string s;

    cin >> test;

    while(test--){
        cin >> n >> s;
        ans = 0;
        for(i = 0; i < s.size(); i++){
            j = s[i] - 48;
            ans = (j + ans * 10) % n;
        }
        cout << ans << endl;
    }
    return 0;
}
