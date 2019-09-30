#include<bits/stdc++.h>
using namespace std;
int main()
{
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    map<char, int> m;
    int n, i, j, k, co;
    string s, ans, temp;

    while(cin >> s){
            co = 0;
        for(i = 0; i < s.size(); i++){
            if(m[s[i]] == 0){
                co++;
                k = co;
                m[s[i]] = co;

                while(k != 0){
                j = k % 10;
                k = k / 10;
            if(j == 2)
                j = 5;
           else if(j == 9)
                j = 6;
            else if(j == 6)
                j = 9;
            else if(j == 5)
                j = 2;
                temp.push_back(j + 48);

            }
            reverse(temp.begin(), temp.end());
             ans += temp;
            temp.clear();
            }
            else{
                    k = m[s[i]];

                    while(k != 0){
                j = k % 10;
                k = k / 10;
            if(j == 2)
                j = 5;
           else if(j == 9)
                j = 6;
            else if(j == 6)
                j = 9;
            else if(j == 5)
                j = 2;
                temp.push_back(j + 48);
            }
            reverse(temp.begin(), temp.end());
             ans += temp;
             temp.clear();
        }
    }
        cout << ans << endl;
        ans.clear();
        m.clear();
    }
    return 0;
}
