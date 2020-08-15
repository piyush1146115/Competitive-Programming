#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, sub, ans;
    map <string, int> m;
    int sz, i, j, k, l, mx;

    while(cin >> sz >> s){

        l = s.size();
        mx = -1;

        for(i = 0; i < l - (sz - 1); i++){
            for(j = i; j <= i + (sz - 1); j++){
                sub.push_back(s[j]);
            }
           // cout << sub << endl;
            m[sub]++;
            if(m[sub] > mx){
                mx = m[sub];
                ans = sub;
            }
            sub.clear();
        }
        cout << ans <<endl;
        m.clear();
    }
    return 0;
}
