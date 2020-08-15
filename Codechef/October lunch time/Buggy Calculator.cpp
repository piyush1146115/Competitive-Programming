#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;

    cin >> test;

    while(test--){
    string s1, s2, res;

    cin >> s1 >> s2;
reverse(s1.begin(), s1.end());
reverse(s2.begin(), s2.end());

    for(int i = 0; i < max((int)s1.size(), (int)s2.size()); i++){
        int add = 0;
        if(i < s1.size())
         add = (s1[i] - '0');

         if(i < s2.size())
            add += (s2[i] - '0');

        add %= 10;
        res.push_back(add +'0');
    }
   reverse(res.begin(), res.end());
    int flag = 1;
    for(int i = 0; i < res.size(); i++){
        if(flag == 1&& res[i] == '0'){
            continue;
        }
        else{
            flag = 0;
        }
        cout << res[i];
    }

    if(flag)
        cout << 0;

    cout << endl;
    }
}
