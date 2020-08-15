#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int i, j, l, flag = 1;

    cin >> s;

    for(i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            s.erase(s.begin() + i);
            flag = 0;
            break;
        }
    }

    if(flag){
        s.erase(s.begin() + 0);
    }

    cout << s << endl;
}
