#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n, k, i, j, test, t = 0;

    cin >> test;

    while(test--){
        t++;
        cin >> n >> k >> s;
        int c = 0;

        for(i = 0; i < n; i++){
            for(j = i -1; j >= 0 && j >= i - k; j--){
                if(s[i] == s[j]){
                    c++;
                    break;
                }
            }
        }
        printf("Case %d: %d\n",t, c);
    s.clear();
    }
    return 0;
}
