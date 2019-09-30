#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
     string s1, s2;
     int i, j, test, cs = 0;
     map <char, int> m1, m2;

     scanf("%d", &test);
     getchar();
     while(test--){
        getline(cin, s1);
        getline(cin, s2);

        for(i = 0; i < s1.size(); i++)
            if(s1[i] >= 'A' && s1[i] <= 'Z')
            s1[i] += 32;

        for(i = 0; i < s2.size(); i++)
            if(s2[i] >= 'A' && s2[i] <= 'Z')
                s2[i] += 32;

        for(i = 0; i < s1.size(); i++){
            if(isalpha(s1[i])){
                m1[s1[i]]++;
            }
        }

        int flag = 1;

        for(i = 0; i < s2.size(); i++){
            if(isalpha(s2[i])){
               m2[s2[i]]++;
            }
        }

        for(i = 0; i  < s2.size(); i++){
            if(isalpha(s2[i])){
                if(m1[s2[i]] != m2[s2[i]]){
                    flag = 0;
                    break;
                }
            }
        }
        //cout << s1<< endl << s2 << endl;
        m1.clear();
        m2.clear();
        printf("Case %d: ", ++cs);

        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
     }
     return 0;
}
