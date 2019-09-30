#include<bits/stdc++.h>
using namespace std;
int flag[10];
int main()
{
    int len, i, j;
    string s;

    cin >> s;
    if(s.size() >= 5){
        for(i = 0; i < s.size(); i++){
          if(s[i] == 'h'){
            flag[1] = 1;
            i++;
            break;
          }
        }
        while(i < s.size()){
            if(s[i] == 'e'){
                flag[2] = 1;
                i++;
                break;
            }
            i++;
        }
          while(i < s.size()){
            if(s[i] == 'l'){
                flag[3] = 1;
                i++;
                break;
            }
            i++;
        }
          while(i < s.size()){
            if(s[i] == 'l'){
                flag[4] = 1;
                i++;
                break;
            }
            i++;
        }
          while(i < s.size()){
            if(s[i] == 'o'){
                flag[5] = 1;
                i++;
                break;
            }
            i++;
        }
    }

    if(flag[1] && flag[2] && flag[3] && flag[4] && flag[5])
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
