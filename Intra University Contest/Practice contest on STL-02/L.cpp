#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, s1, s2;

    map<string, string> mp;

    while(getline(cin, s)){
        if(s == "")
            break;

        stringstream ss(s);
        ss >> s1;
        ss >> s2;

        mp[s2] = s1;
        //cout << s1 << " " << s2 << endl;
    }


    while(getline(cin, s)){
        if(s == "")
            break;

        if(mp.find(s) == mp.end()){
            cout << "eh" << endl;
        }
        else{
            cout << mp[s] << endl;
        }
    }

   // cout << "Hello" << endl;

}
