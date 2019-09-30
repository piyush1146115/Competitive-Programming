#include<bits/stdc++.h>
using namespace std;
int flag[30];
int main()
{
    string s1, s2;
    int i, j, k, f = 0;

    cin >> s1 >> s2;

    for(i = 0; i < s1.size(); i++){
        flag[s1[i] - 'a'] = 1;
    }

    for(i = 0; i < s2.size(); i++){
        if(flag[s2[i] - 'a'] == 0){
            f = 1;
            break;
        }
    }

    if(f)
    {
        printf("-1\n");
    }
    else{
            int c = 1;
            j = 0;
            for(i = 0; i < s2.size(); i++){
                while(1){
                   if(j == s1.size()){
                    j = 0;
                    c++;
                   }
                    if(s1[j] == s2[i]){
                        j++;
                        break;
                    }
                j++;
                }
            }
        cout << c << endl;
    }
    return 0;
}
