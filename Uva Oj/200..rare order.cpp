#include<bits/stdc++.h>
using namespace std;
int main()
{
   // freopen("input.txt", "r", stdin);
    string a[10000], b, s;
    int i, j, k, l, flag[30];
    l = 0;
    while(cin >> b){
        if(b == "#")
            break;
        a[l++] = b;
    }
    memset(flag, 0, sizeof(flag));
    for(i  = 0; i < l ; i++){
        for(j = 0; j < a[i].size(); j++){
            flag[a[i][j] - 'A'] = 1;
        }
    }

    for(i  = 0; i < 22; i++){
        for(j = 0; j < l; j++){
         if(i < a[j].size()){
            if(flag[a[j][i] - 'A'] == 1){
                s.push_back(a[j][i]);
                flag[a[j][i] - 'A'] = 0;
            }
         }
        }
    }
    cout << s << endl;
    s.clear();
}
