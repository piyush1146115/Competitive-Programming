#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s[105], ire1[25], ire2[25];
    int n , l, i, j;

    while(cin >> l >> n){
    for(i = 0; i < l; i++){
        cin >> ire1[i] >> ire2[i];
    }
    for(i = 0; i < n; i++){
        cin >> s[i];
        int flag = 1;
        for(j = 0; j < l; j++){
            if(s[i] == ire1[j]){
                s[i] = ire2[j];
                flag = 0;
                break;
            }
        }
        if(flag){
            int len = s[i].size();
            if(s[i][len - 1] == 'y' && (s[i][len- 2] != 'a' && s[i][len- 2] != 'e' && s[i][len- 2] != 'i' && s[i][len- 2] != 'o' && s[i][len- 2] != 'u')){
                s[i].erase(s[i].begin() + (len - 1));
                s[i] += "ies";
            }
            else if(s[i][len - 1] == 'o' || s[i][len - 1] == 'x' || s[i][len - 1] == 's' || (s[i][len - 1] == 'h' && s[i][len - 2] == 'c') || (s[i][len - 1] == 'h' && s[i][len - 2] == 's')){
                s[i] += "es";
            }
            else
                s[i] += "s";
        }
    }
    for(i = 0; i < n; i++){
        cout << s[i] << endl;
    }
    }
    return 0;
}
