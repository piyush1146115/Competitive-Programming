#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, k, b = 0, r = 0, mn1, mn2, ans;
    string s;

    scanf("%d", &n);
    cin >> s;

    for(i = 0; i < n ; i += 2){
        if(s[i] == 'b')
            b++;
    }
    for(i = 1; i < n; i+= 2)
    {
        if(s[i] == 'r'){
            r++;
        }
    }

    mn1 = abs(b - r) + min(b, r);

    b = 0;
    r = 0;

     for(i = 0; i < n ; i += 2){
        if(s[i] == 'r')
            r++;
    }
    for(i = 1; i < n; i+= 2)
    {
        if(s[i] == 'b'){
            b++;
        }
    }

    mn2 = abs(b - r) + min(b, r);

    cout << min(mn1, mn2) << endl;

    return 0;
}
