#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, k, n;
    string ans, s;

    cin >> n >> s;

    ans = "";

    for(i = 0; i < s.size(); i++)
    {
        if(s[i] == '2'){
            ans += "2";
        }
        else if(s[i] == '3')
            ans += "3";
        else if(s[i] == '4')
        ans += "223";
        else if(s[i] == '5')
            ans += "5";
        else if(s[i] == '6')
            ans += "35";
        else if(s[i] == '7')
            ans += "7";
        else if(s[i] == '8')
            ans += "2227";
        else if(s[i] == '9')
            ans += "2337";
    }
    sort(ans.begin(), ans.end());

    for(i = ans.size() - 1; i >= 0; i--)
        printf("%c",ans[i]);

    printf("\n");
}
