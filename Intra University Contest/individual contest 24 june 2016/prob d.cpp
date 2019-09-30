#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, sub;
    vector<string> v;
    int i, j, k;

    cin >> s;

    for(i = 0; i < s.size(); i++){

        for(k = i; k < s.size(); k++){
                    sub = "";
            for(j = i; j <= k; j++){
                sub += s[j];
            }
            v.push_back(sub);
        }
    }
    int mx = 0;
    for(i = 0; i < v.size(); i++){
       for(j = 0; j < v.size(); j++){
        if(i == j)
            continue;
        if(v[i] == v[j]){
            if(v[i].size() > mx){
                mx = v[i].size();
            }
        }
       }
    }
    cout << mx << endl;

    return 0;
}
