#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, k, flag = 0;
    string s[1005];

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        cin >> s[i];

    for(i = 0; i <n ;i++){
        if(s[i][0] == 'O' && s[i][1] == 'O'){
            s[i][0] = '+';
            s[i][1] = '+';
            flag = 1;
            break;
        }
         if(s[i][3] == 'O' && s[i][4] == 'O'){
            s[i][3] = '+';
            s[i][4] = '+';
            flag = 1;
            break;
        }
    }
    if(flag){
        printf("YES\n");

        for(i = 0; i < n; i++)
            cout << s[i] << endl;
    }
    else
        printf("NO\n");
}
