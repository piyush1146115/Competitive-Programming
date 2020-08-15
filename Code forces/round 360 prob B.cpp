#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, ans;

    cin >> s;
    ans = s;
    reverse(s.begin(), s.end());
    ans += s;

    cout << ans << endl;
}
