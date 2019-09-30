#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    s.push_back('t');
    int flag = 1;
    for(int i = 0; i < n; i++){
        if(s[i] != 'a' && s[i] != 'e' && s[i] != 'o' && s[i] != 'i' && s[i] != 'u' && s[i] != 'n'){
            if(s[i + 1] != 'a' && s[i + 1] != 'e' && s[i + 1] != 'o' && s[i + 1] != 'i' && s[i + 1] != 'u'){
                flag = 0;
            }
        }
    }
    if(flag){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
