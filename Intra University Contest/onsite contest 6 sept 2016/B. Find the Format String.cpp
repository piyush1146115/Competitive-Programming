#include<bits/stdc++.h>
using namespace std;

int main()
{
    int cs = 0, i, j, k, n;
    string s1, s2;
    set<int> s;

    while(scanf("%d", &n) == 1 , n){
        int flag = 1, f1 = 1, f2 = 1, f3 = 1;
        while(n--){
            cin >> s1;
            getchar();
            getline(cin, s2);

            if(s2.size() > s1.size())
            flag = 0;

            if(s2.size() == 0){

                    if(s1[0] >= 48 && s1[0] <= 57 && f1 ==1){
                for(j = 0; j < 9; j++)
                s.insert(j + 48);

                f1 = 0;
                    }
                    else if(s1[0] >= 'A' && s2[0] <= 'Z' && f2 == 1){
                  for(j = 65; j <= 90; j++)
                    s.insert(j);
                    f2 = 0;
                    }
                    else if(s1[0] >= 'a' && s1[0] <= 'z' && f3 == 1){
                       for(j = 97; j <= 122; j++)
                        s.insert(j);
                        f3  = 0;
                    }
            }
            for(i = 0; i < s2.size(); i++){
                    if(!isalpha(s2[i]) && (s2[i] < 48 || s2[i] > 57)){
                    flag = 0;
                    break;
                    }

                if(s1[i] == s2[i]){

                    if(s2[i] >= 48 && s2[i] <= 57 && f1 ==1){
                        for(j = 0; j < 9; j++)
                        s.insert(j + 48);
                        f1 = 0;
                    }
                else if(s2[i] >= 'A' && s2[i] <= 'Z' && f2 == 1){
                        for(j = 65; j <= 90; j++)
                    s.insert(j);
                    f2 = 0;
                }
                else if(s2[i] >= 'a' && s2[i] <= 'z' && f3 == 1){
                    for(j = 97; j <= 122; j++)
                        s.insert(j);
                        f3  = 0;
                }
                }
                else{
                    flag = 0;
                }
            }

        if(s1.size() > s2.size()){
            int b = s1[s2.size()];
            //printf(">>%c\n", b);
            if(s.count(b) != 0)
            s.erase(b);
        }

        }
        printf("Case %d: ", ++cs);

           if(s.size() == 0 || flag == 0){
                printf("I_AM_UNDONE\n");
            }
            else{
                set<int> :: iterator it;

                printf("[");
                for(it = s.begin(); it != s.end(); it++){
                    printf("%c",*it);
                }
                printf("]\n");
                s.clear();
            }
    }
}
