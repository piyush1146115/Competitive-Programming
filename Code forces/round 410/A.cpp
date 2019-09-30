#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int   cnt = 0;
    cin >> s;
    int sz = s.size()/2;

    for(int i = 0; i < sz; i++){
        if(s[i] != s[s.size() - i - 1])
            cnt++;
    }

    if(s.size() == 1 || cnt == 1)
        printf("YES\n");
    else
        printf("NO\n");
}
