#include<bits/stdc++.h>
using namespace std;
int cont[30];
int main()
{
    //freopen("in.txt", "r", stdin);

    int i, j, k, len, pos;
    string s, ans;
    cin >> s;
    len = s.size();

    for(i = 0; i < len; i++){
        cont[s[i] - 'a']++;
    }
    ans = "";
    pos = 0;
    for(i = 25; i >= 0; i--){
        if(cont[i] > 0){
            for(j = pos; j < len; j++){
                if(s[j] == i + 'a'){
                    ans += s[j];
                    pos = j;
                }
            }
            }
        }
    cout << ans << endl;

}
