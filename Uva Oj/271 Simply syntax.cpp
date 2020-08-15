#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int c, i, j;

    while(cin >> s){
            c = 0;
        for(i = s.size() - 1; i >= 0; i--){
            if(s[i] >= 'p' && s[i] <= 'z')
                c++;
            else if(s[i] == 'C' || s[i] == 'D' || s[i] == 'E' || s[i] == 'I'){
                    if(c >= 2)
                        c--;
                    else{
                        c = 0;
                        break;
                    }
            }
           else if(s[i] == 'N'){
                if(c == 0){
                    break;
                }
            }
        }
        if(c == 1){
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}

