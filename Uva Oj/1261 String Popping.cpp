#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    int test, i, j;

    cin >> test;

    while(test--){
        cin >> s;
        for(i = 0; i < s.size(); i++){
            j = i;
          int c = 0 , flag = 0;
            while(i < s.size() - 1){
                if(s[i] == s[i + 1]){
                    c++;
                    i++;
                    flag = 1;
                }
                else
                    break;
            }
            if(c > 0){
                s.erase(s.begin() + j, s.begin() + (j + c + 1));
            }
            //cout << s << endl;
            if(flag)
                i = -1;
        }

    if(s.empty()){
        printf("1\n");
    }
    else
        printf("0\n");
    s.clear();
    }
    return 0;
}
