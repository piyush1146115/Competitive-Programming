#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int i, j, n, test;
    double res;

    cin >> test;

    while(test--){
        cin >> s;
        res = 0.0;
        for(i = 0; i < s.size(); i++){
            n = 0;
            char ch;
            if(isalpha(s[i])){
                ch = s[i];
                i++;
            }
            while(s[i] >= '0' && s[i] <= '9'){
                n = (s[i] - '0') + (n * 10);
                i++;
            }
            i--;
            if(n == 0)
                n = 1;

            if(ch == 'C')
                res += (n * 12.01);
            else if(ch == 'H')
                res += (n * 1.008);
            else if(ch == 'O')
                res += (n * 16.00);
            else if(ch == 'N')
                res += (n * 14.01);
        }

        printf("%.3lf\n", res);
    }
    return 0;
}
