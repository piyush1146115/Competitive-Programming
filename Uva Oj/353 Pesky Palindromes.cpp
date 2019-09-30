#include<bits/stdc++.h>
using namespace std;

bool chk(string s){
string r = s;
reverse(s.begin(), s.end());

if(r == s)
    return true;
else
    return false;
}
int main()
{
    string s, st;
    set <string> se;
    int i, j, k, l, m, n, cn;

    while(cin >> s){

        for(i = 0; i < s.size(); i++){
            for(j = i; j < s.size(); j++){
                for(k = i; k <= j; k++){
                    st.push_back(s[k]);
                }
                se.insert(st);
                st.clear();
            }
        }

        set<string> :: iterator it;
        cn = 0;

        for(it = se.begin(); it != se.end(); it++){
            if(chk(*it))
                cn++;
        }


    cout << "The string '" << s << "' contains " << cn << " palindromes.\n";
    se.clear();
    }
return 0;
}
