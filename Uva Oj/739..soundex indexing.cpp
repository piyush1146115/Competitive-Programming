#include<bits/stdc++.h>
using namespace std;
int main()
{
       //freopen("input.txt", "r", stdin);
       //freopen("output.txt", "w", stdout);

    map<char, int> m;
    vector<int>v;
    int i, j, k, t = 1, flag;
    m['B'] = m['P'] = m['F'] = m['V'] = 1;
    m['C'] = m['S'] = m['K'] = m['G'] = m['J'] = m['Q'] = m['X'] = m['Z'] = 2;
    m['D'] = m['T'] = 3;
    m['L'] = 4;
    m['M'] = m['N'] = 5;
    m['R'] = 6;

    char s[50];

    while(gets(s)){
        int l = strlen(s);
        v.push_back(s[0]);
        flag = 0;
        for(i = 1; i < l; i++){
                    if(s[i] == 'A' || s[i] == 'I' || s[i] == 'E' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y' || s[i] == 'W' || s[i] == 'H'){
                    flag = 1;
                    //continue;
                }

                if(!flag){
                    if(m[s[i]] > 0 && m[s[i]] != v[v.size() - 1] && m[s[i]] != m[s[i - 1]]){
                v.push_back(m[s[i]]);
                flag = 0;
            }
                }

                if(flag){
                    if(m[s[i]] > 0){
                        v.push_back(m[s[i]]);
                        flag = 0;
                    }
                }


            if(v.size() == 4)
                break;

        }
        while(v.size() < 4)
            v.push_back(0);
        if(t){
            printf("         NAME                     SOUNDEX CODE\n");
            t = 0;
        }
        printf("         %s", s);

        k = 35 - l - 10;

        for(i = 0; i < k; i++)
            printf(" ");

        printf("%c",v[0]);
        for(i = 1; i < 4; i++)
            printf("%d",v[i]);

        printf("\n");
        v.clear();
    }
    printf("                   END OF OUTPUT\n");
    return 0;
}
