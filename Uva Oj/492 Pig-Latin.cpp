#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, ans, temp;
    char ch;
    int i, j, k;

    while(getline(cin , s)){
            for(i = 0; i < s.size(); i++){
            if(isalpha(s[i])){
            if(s[i] == 'A' || s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'E' || s[i] == 'O' || s[i] == 'U' || s[i] == 'I' || s[i] == 'i'){
                            while(isalpha(s[i])){
                                temp.push_back(s[i]);
                                i++;
                                if(i == s.size()){
                                    break;
                                }
                            }
                        }
                        else{
                            ch = s[i];
                           i++;
                            while(isalpha(s[i])){
                                temp.push_back(s[i]);
                                i++;
                                if(i == s.size()){
                                    break;
                                }
                        }
                        temp.push_back(ch);
                }
                i--;
                temp += "ay";

                ans += temp;
                temp.clear();
            }
            else{
                ans.push_back(s[i]);
            }
            }
            cout << ans << endl;
            ans.clear();
    }
    return 0;
}
