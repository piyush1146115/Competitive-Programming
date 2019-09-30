#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, test, rem, div[15], n;
    string s;

    cin >> test;

    while(test--){
        cin >> s;
        cin >> n;
        for(i = 0; i < n; i++){
            scanf("%d",&div[i]);
        }
        int flag = 1;
        for(i = 0; i < n; i++){
                rem = 0;
            for(j = 0; j < s.size(); j++){
                rem = ((s[j] - '0') + rem * 10) % div[i];
            }
        if(rem != 0){
            flag = 0;
            break;
        }
        }
        if(flag)
            cout << s << " - Wonderful.\n";
        else
            cout << s << " - Simple.\n";
    }
    return 0;
}
