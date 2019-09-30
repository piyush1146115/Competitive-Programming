#include<bits/stdc++.h>
using namespace std;
int main()
{
  //  freopen("input.txt", "r", stdin);
    string s[1500], st;
    map <char, int>mp, me;
    int i, j, k, l, flag, n, ara[30], ara2[30], co;
    n = 0;
    while(cin >> st){
        if(st == "#")
            break;
        s[n] = st;
        n++;
    }
    getchar();
    while(getline(cin , st)){
        if(st == "#")
            break;
        memset(ara, 0, sizeof(ara));

        for(i = 0; i < st.size(); i++){
            if(st[i] >= 'a' && st[i] <= 'z'){
                mp[st[i]]++;
            }
        }

    co = 0;
    flag = 0;
    for(i= 0; i < n; i++){
            flag = 1;
        for(j = 0; j < s[i].size(); j++){
            me[s[i][j]]++;
        }

        for(k = 0; k < s[i].size(); k++){
            if(mp[s[i][k]] < me[s[i][k]]){
                flag = 0;
            }
        }
        if(flag)
            co++;

            me.clear();
    }
    cout << co << endl;
    mp.clear();
    }
    return 0;
}
