#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;

    int n, k, yes = 0;

    cin >> n >> k;
    cin >> s;
    int i, g;
    for(i = 0; i < n ; i++){
        if(s[i] == 'G'){
          g = i;
        }
    }

    for(i = g; i >= 0; i-= k){
            if(s[i] == '#'){
                    break;
            }
        if(s[i] != '#' && s[i] == 'T')
            yes = 1;
    }

    for(i = g; i < n; i+= k){
            if(s[i] == '#')
            break;
        if(s[i] != '#' && s[i] == 'T')
            yes = 1;
    }

    if(yes)
    printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
