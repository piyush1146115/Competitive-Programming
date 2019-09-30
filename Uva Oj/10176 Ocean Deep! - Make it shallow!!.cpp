#include<bits/stdc++.h>
using namespace std;
int main()
{
   //freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    string num, s;
    int i, j, k = 0, n ;
    while(cin >> s){
        if( k == 0){
            num = s;
            if(s[s.size() - 1] != '#')
                continue;
        }
        else{
            num += s;
              if(s[s.size() - 1] != '#')
                continue;
        }
        k = 1;
        n = 0;

    for(i = 0; i < num.size(); i++)
    {
        if(num[i] >= '0' && num[i] <= '9')
            n = ((num[i] - '0') + (n * 2)) % 131071;
    }
    if(n == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
        num.clear();
        k = 0;
    }
    return 0;
}
