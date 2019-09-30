#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ans = 0, n, i, j;
    string s;

    cin >> n >> s;
int co = 0;
    for(i = 0; i < s.size(); i++){
        if(s[i] == '<')
            ans++;
        else
            ans--;

            if(ans > i)
                co++;
    }
    ans = 0;
    n--;
    for(i = s.size() - 1; i >= 0; i--){
        if(s[i] == '>')
            ans++;
        else
            ans--;

            if(ans > (n - i) )
                co++;
    }
    cout << co << endl;
}
