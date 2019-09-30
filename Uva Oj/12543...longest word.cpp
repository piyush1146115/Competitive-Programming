#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    map<int, string> m;
    string s, a;
    int i, j, mx = -23433, l;

    while(cin >> s){
        if(s == " E-N-D")
            break;
        l = 0;
        for(i = 0; i < s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;

            if(isalpha(s[i]) || s[i] == '-'){
                l++;
                a.push_back(s[i]);
            }
        }
        if(l > mx){
            m[l] = a;
            mx = l;
        }
        a.clear();
    }
    cout << m[mx] << endl;
m.clear();
    return 0;
}
