#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s, temp;
    vector<string>v;
    map<string, int> m, t;
    int i, j;

    while(cin >> s){
        if(s == "#")
            break;
            v.push_back(s);
            m[s]++;

         /*for(i = 0; i < s.size(); i++){
                   if(s[i] >= 'A' && s[i] <= 'Z')
                    s[i] += 32;
                }*/
                transform(s.begin(), s.end(), s.begin() ,:: tolower);
                sort(s.begin(), s.end());
            t[s]++;
    }

    for(i = 0; i < v.size(); i++){
        temp = v[i];
    transform(temp.begin(), temp.end(), temp.begin(), :: tolower);

         /*for(j = 0; j < temp.size(); j++){
                   if(temp[j] >= 'A' && temp[j] <= 'Z')
                    temp[j] += 32;
                }*/
         sort(temp.begin(), temp.end());
        if(t[temp] > 1){
            m[v[i]] = 0;
        }
    }
    map<string , int> :: iterator it;
    for(it = m.begin(); it != m.end(); it++){
        if((*it).second == 1){
            cout << (*it).first << endl;
        }
    }
    m.clear();
    t.clear();
    v.clear();
    return 0;
}
