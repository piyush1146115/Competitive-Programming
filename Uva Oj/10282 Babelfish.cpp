#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    map<string, string> m;
    string s1, s2;

        while(getline(cin, s1)){
            if(s1 == "")
            break;

        stringstream ss(s1);

        ss >> s1 >> s2;

        m[s2] = s1;
        //cout << m[s2] << endl;
        }

        while(cin >> s1){
            if(m[s1] == ""){
                printf("eh\n");
            }
            else
                cout << m[s1] << endl;
        }
        return 0;
}
