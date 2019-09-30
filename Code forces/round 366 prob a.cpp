#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2, ans;

    s1 = "I hate that ";
    s2 = "I love that ";

    int n, i, j;

    cin >> n;

    for(i = 1; i < n ;i++){
        if(i % 2 == 1)
            ans += s1;
        else
            ans += s2;
    }
    if(n % 2 == 0)
        ans += "I love it";
    else
        ans += "I hate it";

    cout << ans << endl;
}
