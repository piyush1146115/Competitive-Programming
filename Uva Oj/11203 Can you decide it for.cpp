#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c[5], i, j, flag, test, m, e;
    string s;
//freopen("input.txt", "r", stdin);

    scanf("%d",&test);

    while(test--){
        c[0] = c[1] = c[2] = c[3] = 0;
        cin >> s;
        flag = 1;
        m = e = 0;
        int f = 0, g = 0;
        for(i = 0; i < s.size(); i++){
            if(s[i] != 'M' && s[i] != 'E' && s[i] != '?')
            {
                flag = 0;
                break;
            }
            if(s[i] == 'M')
            {
                m++;
                f = 1;
                continue;
            }
            if(s[i] == 'E'){
                g = 1;
                e++;
                continue;
            }
            if(g){
                c[2]++;
                continue;
            }
            if(f){
                c[1]++;
                continue;
            }
            c[0]++;
        }

        if(m > 1 || e > 1)
            flag = 0;

        if(c[0] >= 1 && c[1] >= 1 && c[2] >= 2 && flag && c[0] + c[1] == c[2]){
            printf("theorem\n");
        }
        else
            printf("no-theorem\n");
    }
    return 0;
}
