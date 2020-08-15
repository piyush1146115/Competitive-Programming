#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, k, l;
    string s;

    while(scanf("%d",&l) == 1 && l != 0){
        cin >> s;

        int d = 0, r = 0, cont, mn = 200000000;

        for(i = 0; i < l; i++){
            if(s[i] == 'Z'){
                mn = 0;
                break;
            }
            if(s[i] == 'R'){
                if(d)
                mn = min(mn, cont);
                cont = 1;
                r = 1;
                d = 0;
                continue;
            }
            if(s[i] == 'D'){
                if(r)
                mn = min(mn, cont);
                d = 1;
                r = 0;
                cont = 1;
                continue;
            }
            if(d || r)
                cont++;
        }

        printf("%d\n",mn);
    }
    return 0;
}
