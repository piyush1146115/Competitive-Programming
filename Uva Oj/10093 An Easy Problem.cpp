#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int i, j, k, mx, n, m;
    string s;

    while(getline(cin, s)){

            int flag = 0;
            mx = 0;
            k = 0;

        for(i = 0; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                k = s[i] - 48;
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                k = s[i] - 55;
            }
            else if(s[i] >= 'a' && s[i] <= 'z'){
                k = s[i] - 61;
            }
            mx = max(mx, k);
        }

        if(mx == 0)
            mx++;

            while(mx <= 61){
        n = mx + 1;
        m = 0;

        for(i = 0; i < s.size(); i++){
            if(s[i] == ' ' || s[i] == '+' || s[i] == '-')
            continue;
        k = 0;
            if(s[i] >= '0' && s[i] <= '9'){
                k = s[i] - 48;
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                k = s[i] - 55;
            }
            else if(s[i] >= 'a' && s[i] <= 'z'){
                k = s[i] - 61;
            }
            m = (k + (m * n)) % mx;
        }
    if(m == 0)
        break;
        mx++;
            }


if(m != 0){
    printf("such number is impossible!\n");
}
    else if(mx <= 1){
        printf("2\n");
    }
    else{
        printf("%d\n", mx + 1);
    }
    }
    return 0;
}
