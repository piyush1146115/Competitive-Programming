#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d", &test);

    while(test--){
        int k;
        scanf("%d", &k);
        string s;
        cin >> s;
                    int bf = -1, af = -1;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '?'){

                    if(i == ((int)s.size() - 1) && i != 0){
                         bf = s[i - 1] - '0';
                         af = s[0] - '0';
                    }
                    else if(i > 0){
                        bf = s[i - 1] - '0';
                        af = s[i + 1] - '0';
                    }
                    else if(i == 0){
                        if((i + 1) < s.size()){
                        af = s[i + 1] - '0';
                        }
                        if(s.size() > 1){
                        bf = s[s.size() - 1] - '0';
                        }
                    }

                for(int j = 0; j < k; j++){
                    if(j != af && j != bf){
                        s[i] = j + '0';
                    //    cout << "ok" << endl;
                        break;
                    }
                }
            }
        }

        int flag = 0;


        for(int i = 0; i < s.size(); i++){

                    if(i == (s.size() - 1) && i != 0){
                         if(s[i] == s[i - 1] || s[i] == s[0] || s[i] == '?')
                            flag = 1;
                    }
                    else if(i > 0){
                        if(s[i] == '?' || s[i] == s[i - 1] || s[i] == s[i + 1])
                            flag = 1;
                    }
                    else if(i == 0){
                        if(i + 1 < s.size()){
                            if(s[i] == '?' || s[i] == s[i - 1]){
                                flag = 1;
                            }
                        }
                    }
        }

        if(flag){
            printf("NO\n");
        }
        else{
            cout << s << endl;
        }
    }
}
